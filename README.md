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

### Example
#### Example 1
| Specification | Value         |
|---------------|---------------|
| Cache type    | Direct Mapped |
| Cache size    | 4 KB          |
| Block size    | 4 B           |
```bash
./bin/Simulator input/gcc_ld_trace.txt --direct-mapped 4 --size 4
```

#### Example 2
| Specification            | Value               |
|--------------------------|---------------------|
| Cache type               | Associativity       |
| Cache size               | 1024 KB             |
| N-way    		           | 4                   |
| Replacement Algorithm    | Least Recently Used |
```bash
./bin/Simulator input/gcc_ld_trace.txt --associativity 4 --size 1024 --least-recently-used
```

## Address File
An address file fed to this simulator must be conform to the following pattern:
```
name_label
address
address
...
```
#### Example
```
gcc_ld_trace
0x40119618
0x1ffff1d0
0x40119618
0x1ffff1d0
0x1ffff1d0
```

## Report
### Direct Mapped
Command:
```bash
./bin/Simulator input/gcc_ld_trace.txt --direct-mapped <block_size> --size <cache_size>
```
#### Hit
<table style="text-align: center;">
  <tr>
    <th colspan="5">Direct mapped (Hit)</th>
  </tr>
  <tr>
    <td rowspan="2"><b>Block Size<br>(Bytes)</b></td>
    <td colspan="4"><b>Cache Size(KB)</b></td>
  </tr>
  <tr>
    <td><b>4</b></td>
    <td><b>8</b></td>
    <td><b>16</b></td>
    <td><b>32</b></td>
  </tr>
  <tr>
    <td><b>4</b></td>
    <td>1669560</td>
    <td>1775198</td>
    <td>1849934</td>
    <td>1895088</td>
  </tr>
  <tr>
    <td><b>8</b></td>
    <td>1652147</td>
    <td>1766215</td>
    <td>1846558</td>
    <td>1895885</td>
  </tr>
  <tr>
    <td><b>16</b></td>
    <td>1677463</td>
    <td>1784151</td>
    <td>1860161</td>
    <td>1906747</td>
  </tr>
  <tr>
    <td><b>32</b></td>
    <td>1687566</td>
    <td>1793431</td>
    <td>1867498</td>
    <td>1911848</td>
  </tr>
</table>

#### Miss
<table style="text-align: center;">
  <tr>
    <th colspan="5">Direct mapped (Miss)</th>
  </tr>
  <tr>
    <td rowspan="2"><b>Block Size<br>(Bytes)</b></td>
    <td colspan="4"><b>Cache Size(KB)</b></td>
  </tr>
  <tr>
	<td><b>4</b></td>
	<td><b>8</b></td>
	<td><b>16</b></td>
	<td><b>32</b></td>
  </tr>
  <tr>
    <td><b>4</b></td>
    <td>330440</td>
    <td>224802</td>
    <td>150066</td>
    <td>104912</td>
  </tr>
  <tr>
    <td><b>8</b></td>
    <td>347853</td>
    <td>233785</td>
    <td>153442</td>
    <td>104115</td>
  </tr>
  <tr>
    <td><b>16</b></td>
    <td>322537</td>
    <td>215849</td>
    <td>139839</td>
    <td>93253</td>
  </tr>
  <tr>
    <td><b>32</b></td>
    <td>312434</td>
    <td>206569</td>
    <td>132502</td>
    <td>88152</td>
  </tr>
</table>

#### Miss rate
<table style="text-align: center;">
  <tr>
    <th colspan="5">Direct mapped (Miss rate)</th>
  </tr>
  <tr>
    <td rowspan="2"><b>Block Size<br>(Bytes)</b></td>
    <td colspan="4"><b>Cache Size(KB)</b></td>
  </tr>
  <tr>
    <td><b>4</b></td>
    <td><b>8</b></td>
    <td><b>16</b></td>
    <td><b>32</b></td>
  </tr>
  <tr>
    <td><b>4</b></td>
    <td>0.1652</td>
    <td>0.1124</td>
    <td>0.0750</td>
    <td>0.0525</td>
  </tr>
  <tr>
    <td><b>8</b></td>
    <td>0.1739</td>
    <td>0.1169</td>
    <td>0.0767</td>
    <td>0.0521</td>
  </tr>
  <tr>
    <td><b>16</b></td>
    <td>0.1613</td>
    <td>0.1079</td>
    <td>0.0699</td>
    <td>0.0466</td>
  </tr>
  <tr>
    <td><b>32</b></td>
    <td>0.1562</td>
    <td>0.1033</td>
    <td>0.0663</td>
    <td>0.0441</td>
  </tr>
</table>

### Associativity
Command:
```bash
./bin/Simulator input/gcc_ld_trace.txt --associativity <n_way> --size <cache_size> [--round-robin | --least-recently-used]
```
#### Hit
<table style="text-align: center;">
  <tr>
    <th colspan="5">Associativity (Hit)</th>
  </tr>
  <tr>
    <td rowspan="2"><b>Cache Size <br>(KB)</b></td>
    <td colspan="2"><b>Two-way</b></td>
    <td colspan="2"><b>Four-Way</b></td>
  </tr>
  <tr>
    <td><b>LRU</b></td>
    <td><b>RR</b></td>
    <td><b>LRU</b></td>
    <td><b>RR</b></td>
  </tr>
  <tr>
    <td><b>1</b></td>
    <td>1491704</td>
    <td>1458831</td>
    <td>1527679</td>
    <td>1475129</td>
  </tr>
  <tr>
    <td><b>4</b></td>
    <td>1759588</td>
    <td>1740139</td>
    <td>1786471</td>
    <td>1759111</td>
  </tr>
  <tr>
    <td><b>8</b></td>
    <td>1834446</td>
    <td>1821673</td>
    <td>1852267</td>
    <td>1834498</td>
  </tr>
  <tr>
    <td><b>32</b></td>
    <td>1939563</td>
    <td>1934739</td>
    <td>1950492</td>
    <td>1943335</td>
  </tr>
  <tr>
    <td><b>512</b></td>
    <td>1974599</td>
    <td>1974538</td>
    <td>1974745</td>
    <td>1974736</td>
  </tr>
  <tr>
    <td><b>1024</b></td>
    <td>1974717</td>
    <td>1974691</td>
    <td>1974753</td>
    <td>1974753</td>
  </tr>
</table>

#### Miss
<table style="text-align: center;">
  <tr>
    <th colspan="5">Associativity (Miss)</th>
  </tr>
  <tr>
    <td rowspan="2"><b>Cache Size <br>(KB)</b></td>
    <td colspan="2"><b>Two-way</b></td>
    <td colspan="2"><b>Four-Way</b></td>
  </tr>
  <tr>
    <td><b>LRU</b></td>
    <td><b>RR</b></td>
    <td><b>LRU</b></td>
    <td><b>RR</b></td>
  </tr>
  <tr>
    <td><b>1</b></td>
    <td>508296</td>
    <td>541169</td>
    <td>472321</td>
    <td>524871</td>
  </tr>
  <tr>
    <td><b>4</b></td>
    <td>240412</td>
    <td>259861</td>
    <td>213529</td>
    <td>240889</td>
  </tr>
  <tr>
    <td><b>8</b></td>
    <td>165554</td>
    <td>178327</td>
    <td>147733</td>
    <td>165502</td>
  </tr>
  <tr>
    <td><b>32</td>
    <td>60437</td>
    <td>65261</td>
    <td>49508</td>
    <td>56665</td>
  </tr>
  <tr>
    <td><b>512</b></td>
    <td>25401</td>
    <td>25462</td>
    <td>25255</td>
    <td>25264</td>
  </tr>
  <tr>
    <td><b>1024</b></td>
    <td>25283</td>
    <td>25309</td>
    <td>25247</td>
    <td>25247</td>
  </tr>
</table>

#### Miss rate
<table style="text-align: center;">
  <tr>
    <th colspan="5">Associativity (Miss rate)</th>
  </tr>
  <tr>
    <td rowspan="2"><b>Cache Size <br>(KB)</b></td>
    <td colspan="2"><b>Two-way</b></td>
    <td colspan="2"><b>Four-Way</b></td>
  </tr>
  <tr>
    <td><b>LRU</b></td>
    <td><b>RR</b></td>
    <td><b>LRU</b></td>
    <td><b>RR</b></td>
  </tr>
  <tr>
    <td><b>1</b></td>
    <td>0.2541</td>
    <td>0.2706</td>
    <td>0.2362</td>
    <td>0.2624</td>
  </tr>
  <tr>
    <td><b>4</b></td>
    <td>0.1202</td>
    <td>0.1299</td>
    <td>0.1068</td>
    <td>0.1204</td>
  </tr>
  <tr>
    <td><b>8</b></td>
    <td>0.0828</td>
    <td>0.0892</td>
    <td>0.0739</td>
    <td>0.0828</td>
  </tr>
  <tr>
    <td><b>32</b></td>
    <td>0.0302</td>
    <td>0.0326</td>
    <td>0.0248</td>
    <td>0.0283</td>
  </tr>
  <tr>
    <td><b>512</b></td>
    <td>0.0127</td>
    <td>0.0127</td>
    <td>0.0126</td>
    <td>0.0126</td>
  </tr>
  <tr>
    <td><b>1024</b></td>
    <td>0.0126</td>
    <td>0.0127</td>
    <td>0.0126</td>
    <td>0.0126</td>
  </tr>
</table>

## License

This project is licensed under the MIT License - see the [LICENSE.md](LICENSE.md) file for details
