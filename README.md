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

## Report
### Direct Mapped: Hit
<table style="text-align: center;">
  <tr>
    <th colspan="5">Direct mapped (Hit)</th>
  </tr>
  <tr>
    <td rowspan="2">Block Size<br>(Bytes)</td>
    <td colspan="4">Cache Size(KB)</td>
  </tr>
  <tr>
    <td>4</td>
    <td>8</td>
    <td>16</td>
    <td>32</td>
  </tr>
  <tr>
    <td>4</td>
    <td>1669560</td>
    <td>1775198</td>
    <td>1849934</td>
    <td>1895088</td>
  </tr>
  <tr>
    <td>8</td>
    <td>1652147</td>
    <td>1766215</td>
    <td>1846558</td>
    <td>1895885</td>
  </tr>
  <tr>
    <td>16</td>
    <td>1677463</td>
    <td>1784151</td>
    <td>1860161</td>
    <td>1906747</td>
  </tr>
  <tr>
    <td>32</td>
    <td>1687566</td>
    <td>1793431</td>
    <td>1867498</td>
    <td>1911848</td>
  </tr>
</table>

### Direct Mapped: Miss
<table style="text-align: center;">
  <tr>
    <th colspan="5">Direct mapped (Miss)</th>
  </tr>
  <tr>
    <td rowspan="2">Block Size<br>(Bytes)</td>
    <td colspan="4">Cache Size(KB)</td>
  </tr>
  <tr>
    <td>4</td>
    <td>8</td>
    <td>16</td>
    <td>32</td>
  </tr>
  <tr>
    <td>4</td>
    <td>330441</td>
    <td>224803</td>
    <td>150067</td>
    <td>104913</td>
  </tr>
  <tr>
    <td>8</td>
    <td>347854</td>
    <td>233786</td>
    <td>153443</td>
    <td>104116</td>
  </tr>
  <tr>
    <td>16</td>
    <td>322538</td>
    <td>215850</td>
    <td>139840</td>
    <td>93254</td>
  </tr>
  <tr>
    <td>32</td>
    <td>312435</td>
    <td>206570</td>
    <td>132503</td>
    <td>88153</td>
  </tr>
</table>

### Direct Mapped: Miss rate
<table style="text-align: center;">
  <tr>
    <th colspan="5">Direct mapped (Miss rate)</th>
  </tr>
  <tr>
    <td rowspan="2">Block Size<br>(Bytes)</td>
    <td colspan="4">Cache Size(KB)</td>
  </tr>
  <tr>
    <td>4</td>
    <td>8</td>
    <td>16</td>
    <td>32</td>
  </tr>
  <tr>
    <td>4</td>
    <td>0.165</td>
    <td>0.112</td>
    <td>0.075</td>
    <td>0.052</td>
  </tr>
  <tr>
    <td>8</td>
    <td>0.174</td>
    <td>0.117</td>
    <td>0.077</td>
    <td>0.052</td>
  </tr>
  <tr>
    <td>16</td>
    <td>0.161</td>
    <td>0.108</td>
    <td>0.070</td>
    <td>0.047</td>
  </tr>
  <tr>
    <td>32</td>
    <td>0.156</td>
    <td>0.103</td>
    <td>0.066</td>
    <td>0.044</td>
  </tr>
</table>

## License

This project is licensed under the MIT License - see the [LICENSE.md](LICENSE.md) file for details
