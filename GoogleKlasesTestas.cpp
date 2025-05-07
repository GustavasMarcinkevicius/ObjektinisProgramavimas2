
#include <gtest/gtest.h>
#include "Struktura.h" 

// Test the constructor of Studentas
TEST(StudentasTest, ConstructorTest) {
    Studentas student;
    student.setVardas("Jonas");
    student.setPavarde("Jonaitis");

    EXPECT_EQ(student.getVardas(), "Jonas");
    EXPECT_EQ(student.getPavarde(), "Jonaitis");
}

// Test the copy constructor of Studentas
TEST(StudentasTest, CopyConstructorTest) {
    Studentas original;
    original.setVardas("Jonas");
    original.setPavarde("Jonaitis");
    original.getPazymiai().push_back(10);
    original.setEgzaminoPazimys(8);
    
    Studentas copy = original;  // Copy constructor
    
    EXPECT_EQ(copy.getVardas(), "Jonas");
    EXPECT_EQ(copy.getPavarde(), "Jonaitis");
    EXPECT_EQ(copy.getPazymiai().size(), 1);
    EXPECT_EQ(copy.getPazymiai()[0], 10);
    EXPECT_EQ(copy.getEgzaminoPazimys(), 8);
}

// Test the copy assignment operator of Studentas
TEST(StudentasTest, CopyAssignmentOperatorTest) {
    Studentas original;
    original.setVardas("Jonas");
    original.setPavarde("Jonaitis");
    original.getPazymiai().push_back(9);
    original.setEgzaminoPazimys(7);

    Studentas assigned;
    assigned = original;  // Copy assignment operator

    EXPECT_EQ(assigned.getVardas(), "Jonas");
    EXPECT_EQ(assigned.getPavarde(), "Jonaitis");
    EXPECT_EQ(assigned.getPazymiai().size(), 1);
    EXPECT_EQ(assigned.getPazymiai()[0], 9);
    EXPECT_EQ(assigned.getEgzaminoPazimys(), 7);
}

// Test the move constructor of Studentas
TEST(StudentasTest, MoveConstructorTest) {
    Studentas original;
    original.setVardas("Jonas");
    original.setPavarde("Jonaitis");
    original.getPazymiai().push_back(10);
    original.setEgzaminoPazimys(8);

    Studentas moved = std::move(original);  // Move constructor

    EXPECT_EQ(moved.getVardas(), "Jonas");
    EXPECT_EQ(moved.getPavarde(), "Jonaitis");
    EXPECT_EQ(moved.getPazymiai().size(), 1);
    EXPECT_EQ(moved.getPazymiai()[0], 10);
    EXPECT_EQ(moved.getEgzaminoPazimys(), 8);
    EXPECT_EQ(original.getVardas(), "");  
    EXPECT_EQ(original.getPavarde(), "");
}

// Test the move assignment operator of Studentas
TEST(StudentasTest, MoveAssignmentOperatorTest) {
    Studentas original;
    original.setVardas("Jonas");
    original.setPavarde("Jonaitis");
    original.getPazymiai().push_back(9);
    original.setEgzaminoPazimys(7);

    Studentas moved;
    moved = std::move(original);  // Move assignment operator

    EXPECT_EQ(moved.getVardas(), "Jonas");
    EXPECT_EQ(moved.getPavarde(), "Jonaitis");
    EXPECT_EQ(moved.getPazymiai().size(), 1);
    EXPECT_EQ(moved.getPazymiai()[0], 9);
    EXPECT_EQ(moved.getEgzaminoPazimys(), 7);
    EXPECT_EQ(original.getVardas(), "");  
    EXPECT_EQ(original.getPavarde(), "");
}

// Test the readFromConsole function
TEST(StudentasTest, ReadFromConsoleTest) {

    Studentas student;
    
// Test imput
    student.setVardas("Jonas");
    student.setPavarde("Jonaitis");
    student.getPazymiai().push_back(9);
    student.setEgzaminoPazimys(7);

    EXPECT_EQ(student.getVardas(), "Jonas");
    EXPECT_EQ(student.getPavarde(), "Jonaitis");
    EXPECT_EQ(student.getPazymiai().size(), 1);
    EXPECT_EQ(student.getPazymiai()[0], 9);
    EXPECT_EQ(student.getEgzaminoPazimys(), 7);
}

// Test the print function 
TEST(StudentasTest, PrintTest) {
    Studentas student;
    student.setVardas("Jonas");
    student.setPavarde("Jonaitis");
    
    // Print
    testing::internal::CaptureStdout();
    student.print();
    std::string output = testing::internal::GetCapturedStdout();
    
    EXPECT_TRUE(output.find("Jonas") != std::string::npos);
    EXPECT_TRUE(output.find("Jonaitis") != std::string::npos);
}

// Main function to run the tests
int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
