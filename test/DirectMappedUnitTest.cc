#include "gtest/gtest.h"
#include "DirectMapped.h"

TEST(DirectMapped, Initialize) {
	unsigned long cacheSize = 4 * (1 << 10);
	unsigned long blockSize = 4;
	DirectMapped dm(cacheSize, blockSize);

	EXPECT_EQ(1024ul, dm.getEntrySize());
	EXPECT_EQ(20u, dm.getTagLength());
	EXPECT_EQ(10u, dm.getIndexLength());
	EXPECT_EQ(0u, dm.getBlockOffsetLength());
	EXPECT_EQ(2u, dm.getByteOffsetLength());
}
