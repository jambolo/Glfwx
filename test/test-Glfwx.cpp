#include <Glfwx/Glfwx.h>

#include <gtest/gtest.h>

TEST(GlfwxTest, init_terminate)
{
    ASSERT_TRUE(Glfwx::init());
    ASSERT_EQ(glfwGetError(nullptr), GLFW_NO_ERROR);
    Glfwx::terminate();
    EXPECT_EQ(glfwGetError(nullptr), GLFW_NO_ERROR);
}

TEST(GlfwxTest, requiredInstanceExtensions)
{
    Glfwx::Instance instance;
    std::vector<char const *> extensions = Glfwx::requiredInstanceExtensions();
    ASSERT_EQ(glfwGetError(nullptr), GLFW_NO_ERROR);
    EXPECT_GT(extensions.size(), 0);
}

TEST(GlfwxTest, Instance)
{
    ASSERT_NO_THROW(Glfwx::Instance instance);
}

int main(int argc, char ** argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    int rv = RUN_ALL_TESTS();
    return rv;
}
