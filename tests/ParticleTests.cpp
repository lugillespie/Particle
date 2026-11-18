#include <gtest/gtest.h>
#include "Random.h"

// TEST(Particle,ctor)
// {
//   ASSERT_TRUE(1==0);
// }

TEST(Random,positiveFloat)
{
  for(int i=0; i<100; ++i)
  {
    auto v=Random::randomPositiveFloat();
    EXPECT_TRUE(v>0.0f && v<=1.0f);
  }

  for(int i=0; i<100; ++i)
  {
    auto v=Random::randomPositiveFloat(20);
    EXPECT_TRUE(v>0.0f && v<=20.0f);
  }
}