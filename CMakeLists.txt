cmake_minimum_required(VERSION 3.21)
project(Algorithm_trainning)

set(CMAKE_CXX_STANDARD 14)

add_executable(subdomainVisits LeetCode_Everyday_cpp/subdomainVisits.cpp)
add_executable(threeEqualParts LeetCode_Everyday_cpp/threeEqualParts.cpp)
add_executable(advantageCount LeetCode_Everyday_cpp/advantageCount.cpp)
add_executable(scoreOfParentheses LeetCode_Everyday_cpp/scoreOfParentheses.cpp)
add_executable(possibleBipartition LeetCode_Everyday_cpp/possibleBipartition.cpp)

add_executable(MingRand csp/train/MingRand.cpp)
add_executable(polynorm_maker csp/train/polynorm_maker.cpp)
add_executable(BigIntMul csp/train/BigInt/BigIntMul.cpp)
add_executable(bigInt csp/train/BigInt/bigInt.cpp)
add_executable(fact csp/train/fact.cpp)
add_executable(leet csp/train/BigInt/leet.cpp)
add_executable(MeanGroup csp/train/MeanGroup.cpp)
add_executable(carpet_cover csp/train/carpet_cover.cpp)
add_executable(reverse_pair csp/train/reverse_pair.cpp)
add_executable(point-dist csp/train/point-dist.cpp)

add_executable(cowHouse LoGu/cowHouse.cpp)
add_executable(loop csp/NOIP/2005/loop.cpp)
add_executable(atMostNGivenDigitSet LeetCode_Everyday_cpp/atMostNGivenDigitSet.cpp)
add_executable(HowToEncode csp/202209/HowToEncode.cpp)
add_executable(poster csp/202209/poster.cpp)
add_executable(antipand csp/202209/antipand.cpp)
add_executable(norm csp/202206/norm.cpp)
add_executable(small_map csp/202206/small_map.cpp)
add_executable(kthGrammar LeetCode_Everyday_cpp/kthGrammar.cpp)
add_executable(uninit csp/202203/uninit.cpp)