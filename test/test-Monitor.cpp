#include <Glfwx/Monitor.h>

#include <Glfwx/Glfwx.h>
#include <gtest/gtest.h>
#include <nlohmann/json.hpp>

using json = nlohmann::json;

namespace nlohmann
{

    template <>
    struct adl_serializer<Glfwx::Monitor::VideoMode>
    {
        static void to_json(json & j, Glfwx::Monitor::VideoMode const & mode)
        {
            j = json({
                { "width",       mode.width },
                { "height",      mode.height },
                { "redBits",     mode.redBits },
                { "greenBits",   mode.greenBits },
                { "blueBits",    mode.blueBits },
                { "refreshRate", mode.refreshRate }
                });
        }
    };

    template <>
    struct adl_serializer<Glfwx::Monitor::GammaRamp>
    {
        static void to_json(json & j, Glfwx::Monitor::GammaRamp const & ramp)
        {
            j = json({
                { "red", std::vector<unsigned short>(ramp.red, ramp.red+ramp.size) },
                { "green", std::vector<unsigned short>(ramp.green, ramp.green + ramp.size) },
                { "blue", std::vector<unsigned short>(ramp.blue, ramp.blue + ramp.size) },
                { "size", ramp.size }
                });
        }
    };

    template <>
    struct adl_serializer<Glfwx::Monitor>
    {
        static void to_json(json & j, Glfwx::Monitor const & m)
        {
            std::string name = m.name();

            int positionX = -1;
            int positionY = -1;
            m.position(&positionX, &positionY);

            int sizeX = -1;
            int sizeY = -1;
            m.size(&sizeX, &sizeY);

            float scaleX = 0;
            float scaleY = 0;
            m.scale(&scaleX, &scaleY);

            struct
            {
                int positionX = -1;
                int positionY = -1;
                int sizeX = -1;
                int sizeY = -1;
            } workArea;
            m.workArea(&workArea.positionX, &workArea.positionY, &workArea.sizeX, &workArea.sizeY);

            Glfwx::Monitor::GammaRamp ramp = m.gammaRamp();

            Glfwx::Monitor::VideoMode mode = m.videoMode();

            j = json({
                { "name", name },
                { "position", json::array({ positionX, positionY }) },
                { "size", json::array({ sizeX, sizeY }) },
                { "scale", json::array({ scaleX, scaleY }) },
                { "workArea", json::array({ workArea.positionX, workArea.positionY, workArea.sizeX, workArea.sizeY }) },
                { "gammaRamp", ramp },
                { "videoMode", mode }
                });
        }
    };

}

class MonitorTest : public testing::Test
{
public:
    MonitorTest() = default;
    ~MonitorTest() = default;

    Glfwx::Instance glfwx_;
};

TEST_F(MonitorTest, enumerate)
{
    std::vector<Glfwx::Monitor> monitors = Glfwx::Monitor::enumerate();
    EXPECT_GT(monitors.size(), 0);
    std::cerr << json(monitors).dump(2) << std::endl;
}

TEST_F(MonitorTest, primary)
{
    Glfwx::Monitor monitor = Glfwx::Monitor::primary();
    EXPECT_NE((GLFWmonitor *)monitor, nullptr);
    std::cerr << json(monitor).dump(2) << std::endl;

}

TEST_F(MonitorTest, position)
{
    // Nothing really to test here. Just make sure it doesn't crash.
    Glfwx::Monitor monitor = Glfwx::Monitor::primary();
    int positionX = -1;
    int positionY = -1;
    monitor.position(&positionX, &positionY);
    std::cerr << "[" << positionX << ", " << positionY << "]" << std::endl;
}

TEST_F(MonitorTest, workArea)
{
    Glfwx::Monitor monitor = Glfwx::Monitor::primary();
    int positionX = -1;
    int positionY = -1;
    int sizeX = -1;
    int sizeY = -1;
    monitor.workArea(&positionX, &positionY, &sizeX, &sizeY);
    EXPECT_NE(positionX, -1);
    EXPECT_NE(positionY, -1);
    EXPECT_NE(sizeX, -1);
    EXPECT_NE(sizeY, -1);
    std::cerr 
        << "["
        << positionX << ", "
        << positionY << ", "
        << sizeX << ", "
        << sizeY
        << "], " << std::endl;
}

TEST_F(MonitorTest, size)
{
    Glfwx::Monitor monitor = Glfwx::Monitor::primary();
    int sizeX = -1;
    int sizeY = -1;
    monitor.size(&sizeX, &sizeY);
    EXPECT_NE(sizeX, -1);
    EXPECT_NE(sizeY, -1);
    std::cerr << "[" << sizeX << ", " << sizeY << "]" << std::endl;
}

TEST_F(MonitorTest, scale)
{
    Glfwx::Monitor monitor = Glfwx::Monitor::primary();
    float scaleX = 0.0f;
    float scaleY = 0.0f;
    monitor.scale(&scaleX, &scaleY);
    EXPECT_NE(scaleX, 0.0f);
    EXPECT_NE(scaleY, 0.0f);
    std::cerr << "[" << scaleX << ", " << scaleY << "]" << std::endl;
}

TEST_F(MonitorTest, name)
{
    // Nothing really to test here. Just make sure it doesn't crash.
    Glfwx::Monitor monitor = Glfwx::Monitor::primary();
     std::string name = monitor.name();
     std::cerr << R"(")" << name << R"(")" << std::endl;
}

TEST_F(MonitorTest, context_setContext)
{
    Glfwx::Monitor monitor = Glfwx::Monitor::primary();
    EXPECT_EQ(monitor.context(), nullptr);
    int x;
    void * const expected = (void *)&x;
    monitor.setContext(expected);
    EXPECT_EQ(monitor.context(), expected);
}

TEST_F(MonitorTest, DISABLED_setConnectionChangedCallback)
{
/*
    static void setConnectionChangedCallback(std::function<void(Monitor const &, bool)> const & cb)
    {
        handleConnectionChanged_ = cb;
        if (cb)
        {
            glfwSetMonitorCallback(onConnectionChanged);
        }
        else
        {
            glfwSetMonitorCallback(nullptr);
        }
    }
*/
}

TEST_F(MonitorTest, enumerateVideoModes)
{
    // Nothing really to test here. Just make sure it doesn't crash.
    Glfwx::Monitor monitor = Glfwx::Monitor::primary();
    std::vector<Glfwx::Monitor::VideoMode> modes = monitor.enumerateVideoModes();
    std::cerr << json(modes).dump(2) << std::endl;
}

TEST_F(MonitorTest, videoMode)
{
    // Nothing really to test here. Just make sure it doesn't crash.
    Glfwx::Monitor monitor = Glfwx::Monitor::primary();
    Glfwx::Monitor::VideoMode mode = monitor.videoMode();
    std::cerr << json(mode).dump(2) << std::endl;
}

TEST_F(MonitorTest, setGamma)
{
    // Nothing really to test here. Just make sure it doesn't crash.
    Glfwx::Monitor monitor = Glfwx::Monitor::primary();
    monitor.setGamma(2.0f);
}

TEST_F(MonitorTest, gammaRamp_setGammaRamp)
{
    Glfwx::Monitor monitor = Glfwx::Monitor::primary();
    Glfwx::Monitor::GammaRamp ramp = monitor.gammaRamp();
    monitor.setGammaRamp(ramp);
}

int main(int argc, char ** argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    int rv = RUN_ALL_TESTS();
    return rv;
}
