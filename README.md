# Cache Simulator

A cache simulator for studying the factors that affects the performance of cache accesses

## Getting Started

### Prerequisites

This project requires the GNU Compiler Collection (GCC) as the compiler.<br>
See [this link](https://gcc.gnu.org/) for further details about GCC

### Compilation

If you have ever compiled before, please clean an executable program and object files first by running this command in project's root directory. Otherwise, just skip this step.
```bash
make clean
```
Now, you can compile by running this command:
```bash
make
```

## How to use this Cache Simulator
### Usage
```bash
./bin/Simulator [options] <path_to_address_file>
```
### Options
| Option 	| Description 	|
|-----------------------------	|-------------------------------------------------------------------------------------------------------	|
| ``-s, --size <cache_size>`` 	| Set cache size (kilobyte) 	|
| ``-sb, --size-b <cache_size>``	| Set cache size (byte) 	|
| ``-dm, --direct-mapped <block_size>?`` 	| Set cache structure to a direct mapped with specific block size (4 by default) 	|
| ``-as, --associativity <n_way>?`` 	| Set cache structure to an associativity with specific n (2 by default) 	|
| ``-lru, --least-recently-used`` 	| Set least recently used as a replacement algorithm when ``--associativity`` option is triggered (default) 	|
| ``-rr, --round-robin`` 	| Set round robin as a replacement algorithm when ``--associativity`` option is triggered 	|
| ``-h, --help`` 	| Show help message 	|

<b>Note that</b> ``?`` after ``<argument>`` indicates that ``<argument>`` is optional and you can also view this help message by including ``--help`` or ``-h`` option after command.

## License

This project is licensed under the MIT License - see the [LICENSE.md](LICENSE.md) file for details
