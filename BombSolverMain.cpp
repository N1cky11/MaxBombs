#include "BombSolverClass.h"
#include <iostream>
#include <vector>
#include <gtest/gtest.h>
#include <fstream>
#include <sstream>

TEST(BombSolver,vectors) {
BombsSolver bombsSolver;
ASSERT_EQ(2,bombsSolver.findMaxDetonations(std::vector<Point>{Point(2,1,3),Point(6,1,4)} ) ) ;
ASSERT_EQ(1,bombsSolver.findMaxDetonations(std::vector<Point>{Point(1,1,5),Point(10,10,5)} ) ) ;
ASSERT_EQ(5,bombsSolver.findMaxDetonations(std::vector<Point>{Point(1,2,3),Point(2,3,1),Point(3,4,2),Point(4,5,3),Point(5,6,4)} ) ) ;

}
void readPoints(std::istream &in, std::vector<Point> &vec) {
    std::string line;
    while (getline(in, line)) {
        std::stringstream ss(line);
        int x{}, y{}, r{};
        while(ss>>x>>y>>r) {
 vec.emplace_back(Point(x, y, r) ) ;
}
    }
}

int main(int argc, char **argv) {

    std::vector<Point> points{} ;
    std::ifstream in("InputFile.txt") ;
    if(!in.is_open() ) {
            std::cout <<"Failed to open file\n" ;
            return 1 ;
    }

    ::testing::InitGoogleTest() ;
    return RUN_ALL_TESTS() ;

    readPoints(in,points) ;

    BombsSolver bombsSolver;
    std::cout<< "\nMax number of detonated Bombs="<< bombsSolver.findMaxDetonations(points) << "\n";
    return 0;
}
