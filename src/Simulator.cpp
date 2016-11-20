#include <cstdio>
#include <cstring>
#include <cstdlib>

// Enum declaration
enum CacheType {
    DIRECT_MAPPED,
    ASSOCIATIVITY
};
enum ReplacementAlgorithm {
    LEAST_RECENTLY_USED,
    ROUND_ROBIN
};

// Function prototype
void tokenizeArgv(int, char **);
void showUsage(char *);

// Cache structure parameters (by default)
int cacheSize = 4;
CacheType cacheType = CacheType::DIRECT_MAPPED;
int blockSize = 4;
int nWay = 2;
ReplacementAlgorithm replacementAlgorithm = ReplacementAlgorithm::LEAST_RECENTLY_USED;
char *fileName;

bool isSetFileName = false;

int main(int argc, char *argv[]){
    tokenizeArgv(argc, argv);
    
    if(!isSetFileName) {
        fprintf(stderr, "Please specify address file\n\n");
        // Show usage
        showUsage(argv[0]);
        exit(-1);
    }
    
    FILE *fp;
    char buff[1025];
    unsigned long addrTemp;
    
    if(!(fp = fopen(fileName, "r"))) {
        perror(fileName);
        exit(-1);
    }
    
	// Read file
	while (fgets(&buff[0], 1024, fp)) {
		sscanf(buff, "0x%lx", &addrTemp);
		// access(addrTemp);
	}
    
    // TODO: Print current cache structure
    
	// printf("Hit: %7d Miss: %7d\n", HIT, MISS);

}

void showUsage(char *programName) {
    printf("Usage: %s [options] <path_to_address_file>\n\n"
            "Options: \n"
            "  -s, --size <cache_size>\t\tSet cache size (byte)\n"
            "  -skb, --size-kb <cache_size>\t\tSet cache size (kilobyte)\n"
            "  -dm, --direct-mapped <block_size>?\tSet cache structure to a direct mapped with specific block size (4 by default)\n"
            "  -as, --associativity <n_way>?\t\tSet cache structure to an associativity with specific n (2 by default)\n"
            "  -lru, --least-recently-used\t\tSet least recently used as a replacement algorithm when --associativity option is triggered (default)\n"
            "  -rr, --round-robin\t\t\tSet round robin as a replacement algorithm when --associativity option is triggered\n"
            "  -h, --help\t\t\t\tShow this help message\n"
            "Note that '?' after <argument> indicates that <argument> is optional\n", programName);
}

void tokenizeArgv(int argc, char *argv[]) {
    // Tokenize argv
    int argcCount = 1;
    while(argcCount < argc) {
        if(strcmp(argv[argcCount], "--size") == 0 || strcmp(argv[argcCount], "-s") == 0) {
            // Cache size (Byte)
            if(argcCount + 1 < argc) {
                cacheSize = atoi(argv[argcCount + 1]);
            } else {
                // Error
                fprintf(stderr, "%s option requires one argument\n", argv[argcCount]);
                exit(-1);
            }
            argcCount += 2;
        } else if(strcmp(argv[argcCount], "--size-kb") == 0 || strcmp(argv[argcCount], "-skb") == 0) {
            // Cache size (KB)
            if(argcCount + 1 < argc) {
                cacheSize = atoi(argv[argcCount + 1]) * 1000;
            } else {
                // Error
                fprintf(stderr, "%s option requires one argument\n", argv[argcCount]);
                exit(-1);
            }
            argcCount += 2;
        } else if(strcmp(argv[argcCount], "--direct-mapped") == 0 || strcmp(argv[argcCount], "-dm") == 0) {
            // Direct mapped
            cacheType = CacheType::DIRECT_MAPPED;
            if(argcCount + 1 < argc) {
                // Block size (Byte)
                blockSize = atoi(argv[argcCount + 1]);
                argcCount += 2;
            } else {
                // Optional
                argcCount += 1;
            }
        } else if(strcmp(argv[argcCount], "--associativity") == 0 || strcmp(argv[argcCount], "-as") == 0) {
            // Associativity
            cacheType = CacheType::ASSOCIATIVITY;
            if(argcCount + 1 < argc) {
                // n-way
                nWay = atoi(argv[argcCount + 1]);
                argcCount += 2;
            } else {
                // Optional
                argcCount += 1;
            }
        } else if(strcmp(argv[argcCount], "--round-robin") == 0 || strcmp(argv[argcCount], "-rr") == 0) {
            // Set round robin as a replacement algorithm when --associativity is triggered
            replacementAlgorithm = ReplacementAlgorithm::ROUND_ROBIN;
            argcCount += 1;
        } else if(strcmp(argv[argcCount], "--least-recently-used") == 0 || strcmp(argv[argcCount], "-lru") == 0) {
            // Set least recently used as a replacement algorithm when --associativity is triggered
            replacementAlgorithm = ReplacementAlgorithm::LEAST_RECENTLY_USED;
            argcCount += 1;
        } else if(strcmp(argv[argcCount], "--help") == 0 || strcmp(argv[argcCount], "-h") == 0) {
            // Show usage
            showUsage(argv[0]);
            exit(0);
            argcCount += 1;
        } else {
            // File name
            fileName = argv[argcCount];
            isSetFileName = true;
            argcCount += 1;
        }
    }
}
