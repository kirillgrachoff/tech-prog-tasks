#include "TreeTestCase.h"
#include "Tree.h"

using boost::filesystem::path;

void TreeTestCase::SetUp() {
    TestDirLocation() = boost::filesystem::temp_directory_path() / boost::filesystem::unique_path();
    boost::filesystem::create_directories(TestDirLocation());
    for (int i = 0; i < 10; ++i) {
        auto currentPath = TestDirLocation() / (std::string("test_case") + std::to_string(i));
        boost::filesystem::create_directory(currentPath);
        if (i % 4 == 0) {
            boost::filesystem::ofstream((currentPath / "some_file.cpp").c_str());
        }
    }
}

void TreeTestCase::TearDown() {
    boost::filesystem::remove_all(TestDirLocation());
}

boost::filesystem::path& TreeTestCase::TestDirLocation() {
    static boost::filesystem::path testing_dir_path;
    return testing_dir_path;
}

TEST_F(TreeTestCase, construction_test) {
    EXPECT_EQ(GetTree(TestDirLocation().c_str(), false), GetTree(TestDirLocation().c_str(), false));
    EXPECT_FALSE(GetTree(TestDirLocation().c_str(), false) == GetTree(TestDirLocation().c_str(), true));
    EXPECT_ANY_THROW(GetTree("/hello/this/is/fake/dir/I/think/hehehe", true));
    EXPECT_ANY_THROW(GetTree("/hello/this/is/fake/dir/I/think/hehehe", false));
    EXPECT_ANY_THROW(GetTree((TestDirLocation() / "test_case0/some_file.cpp").c_str(), false));
}

TEST_F(TreeTestCase, behaviour_test) {
    auto directoryNode = GetTree((TestDirLocation() / "test_case0").c_str(), false);
    auto fileNode = directoryNode.children[0];
    EXPECT_FALSE(directoryNode == fileNode);
    auto root = GetTree(TestDirLocation().c_str(), false);
    FilterEmptyNodes(root, TestDirLocation().c_str());
    EXPECT_FALSE(root == GetTree(TestDirLocation().c_str(), false));
}
