# Programming Project - x86-C Interface

## Execution Time Analysis (in seconds)
### Debug
| 2^20        | C Kernel | Assembly Kernel |
|-------------|----------|-----------------|
| Run 01      | 0.9      | 0.3             |
| Run 02      | 0.7      | 0.3             |
| Run 03      | 0.6      | 0.2             |
| Run 04      | 0.8      | 0.3             |
| Run 05      | 0.6      | 0.3             |
| Run 06      | 0.8      | 0.2             |
| Run 07      | 0.7      | 0.3             |
| Run 08      | 0.6      | 0.4             |
| Run 09      | 0.5      | 0.2             |
| Run 10      | 0.6      | 0.2             |
| Run 11      | 0.4      | 0.2             |
| Run 12      | 0.4      | 0.3             |
| Run 13      | 0.6      | 0.2             |
| Run 14      | 0.5      | 0.3             |
| Run 15      | 0.5      | 0.2             |
| Run 16      | 0.5      | 0.2             |
| Run 17      | 0.4      | 0.2             |
| Run 18      | 0.5      | 0.2             |
| Run 19      | 0.5      | 0.2             |
| Run 20      | 0.4      | 0.3             |
| Run 21      | 0.5      | 0.2             |
| Run 22      | 0.5      | 0.2             |
| Run 23      | 0.5      | 0.2             |
| Run 24      | 0.5      | 0.3             |
| Run 25      | 0.5      | 0.2             |
| Run 26      | 0.4      | 0.2             |
| Run 27      | 0.6      | 0.2             |
| Run 28      | 0.6      | 0.2             |
| Run 29      | 0.6      | 0.2             |
| Run 30      | 0.5      | 0.2             |
| **Average** | 0.5      | 0.2             |

| 2^24        | C Kernel | Assembly Kernel |
|-------------|----------|-----------------|
| Run 01      | 0.96     | 0.30            |
| Run 02      | 0.81     | 0.29            |
| Run 03      | 0.63     | 0.30            |
| Run 04      | 0.69     | 0.33            |
| Run 05      | 0.70     | 0.31            |
| Run 06      | 0.72     | 0.31            |
| Run 07      | 0.64     | 0.31            |
| Run 08      | 0.69     | 0.34            |
| Run 09      | 0.113    | 0.40            |
| Run 10      | 0.70     | 0.42            |
| Run 11      | 0.66     | 0.38            |
| Run 12      | 0.70     | 0.37            |
| Run 13      | 0.66     | 0.49            |
| Run 14      | 0.61     | 0.42            |
| Run 15      | 0.71     | 0.31            |
| Run 16      | 0.64     | 0.30            |
| Run 17      | 0.93     | 0.32            |
| Run 18      | 0.96     | 0.33            |
| Run 19      | 0.90     | 0.38            |
| Run 20      | 0.73     | 0.31            |
| Run 21      | 0.76     | 0.30            |
| Run 22      | 0.97     | 0.29            |
| Run 23      | 0.69     | 0.29            |
| Run 24      | 0.75     | 0.28            |
| Run 25      | 0.76     | 0.27            |
| Run 26      | 0.111    | 0.30            |
| Run 27      | 0.109    | 0.29            |
| Run 28      | 0.75     | 0.30            |
| Run 29      | 0.69     | 0.28            |
| Run 30      | 0.64     | 0.27            |
| **Average** | 0.77     | 0.32            |

| 2^30        | C Kernel | Assembly Kernel |
|-------------|----------|-----------------|
| Run 01      | 11.291   | 3.865           |
| Run 02      | 4.523    | 2.581           |
| Run 03      | 3.843    | 1.889           |
| Run 04      | 3.867    | 1.892           |
| Run 05      | 4.10     | 1.921           |
| Run 06      | 3.837    | 1.903           |
| Run 07      | 3.797    | 1.872           |
| Run 08      | 3.824    | 1.857           |
| Run 09      | 3.826    | 1.861           |
| Run 10      | 3.915    | 1.888           |
| Run 11      | 3.873    | 1.864           |
| Run 12      | 3.892    | 1.864           |
| Run 13      | 3.766    | 1.878           |
| Run 14      | 3.783    | 1.868           |
| Run 15      | 3.781    | 1.864           |
| Run 16      | 3.875    | 1.885           |
| Run 17      | 3.758    | 1.868           |
| Run 18      | 3.815    | 1.886           |
| Run 19      | 3.802    | 1.867           |
| Run 20      | 3.821    | 1.845           |
| Run 21      | 3.835    | 1.874           |
| Run 22      | 3.829    | 1.860           |
| Run 23      | 3.813    | 1.913           |
| Run 24      | 3.783    | 1.865           |
| Run 25      | 3.742    | 1.868           |
| Run 26      | 3.781    | 1.877           |
| Run 27      | 3.758    | 1.869           |
| Run 28      | 3.880    | 1.881           |
| Run 29      | 3.981    | 1.903           |
| Run 30      | 4.36     | 1.848           |
| **Average** | 4.111    | 1.965           |

### Release
| 2^20        | C Kernel | Assembly Kernel |
|-------------|----------|-----------------|
| Run 01      | 0.5      | 0.4             |
| Run 02      | 0.1      | 0.3             |
| Run 03      | 0.2      | 0.2             |
| Run 04      | 0.2      | 0.2             |
| Run 05      | 0.3      | 0.5             |
| Run 06      | 0.1      | 0.2             |
| Run 07      | 0.2      | 0.2             |
| Run 08      | 0.1      | 0.2             |
| Run 09      | 0.2      | 0.3             |
| Run 10      | 0.1      | 0.3             |
| Run 11      | 0.2      | 0.3             |
| Run 12      | 0.2      | 0.2             |
| Run 13      | 0.2      | 0.2             |
| Run 14      | 0.2      | 0.2             |
| Run 15      | 0.2      | 0.3             |
| Run 16      | 0.2      | 0.3             |
| Run 17      | 0.1      | 0.2             |
| Run 18      | 0.1      | 0.2             |
| Run 19      | 0.1      | 0.3             |
| Run 20      | 0.2      | 0.3             |
| Run 21      | 0.2      | 0.2             |
| Run 22      | 0.2      | 0.1             |
| Run 23      | 0.2      | 0.5             |
| Run 24      | 0.1      | 0.3             |
| Run 25      | 0.2      | 0.3             |
| Run 26      | 0.1      | 0.3             |
| Run 27      | 0.1      | 0.2             |
| Run 28      | 0.2      | 0.2             |
| Run 29      | 0.3      | 0.4             |
| Run 30      | 0.2      | 0.2             |
| **Average** | 0.1      | 0.2             |

| 2^24        | C Kernel | Assembly Kernel |
|-------------|----------|-----------------|
| Run 01      | 0.22     | 0.44            |
| Run 02      | 0.19     | 0.36            |
| Run 03      | 0.16     | 0.32            |
| Run 04      | 0.16     | 0.34            |
| Run 05      | 0.16     | 0.34            |
| Run 06      | 0.21     | 0.29            |
| Run 07      | 0.17     | 0.30            |
| Run 08      | 0.16     | 0.27            |
| Run 09      | 0.16     | 0.31            |
| Run 10      | 0.19     | 0.31            |
| Run 11      | 0.17     | 0.30            |
| Run 12      | 0.19     | 0.31            |
| Run 13      | 0.21     | 0.35            |
| Run 14      | 0.19     | 0.31            |
| Run 15      | 0.21     | 0.32            |
| Run 16      | 0.25     | 0.33            |
| Run 17      | 0.27     | 0.33            |
| Run 18      | 0.31     | 0.32            |
| Run 19      | 0.27     | 0.30            |
| Run 20      | 0.32     | 0.31            |
| Run 21      | 0.30     | 0.30            |
| Run 22      | 0.31     | 0.33            |
| Run 23      | 0.23     | 0.27            |
| Run 24      | 0.41     | 0.29            |
| Run 25      | 0.36     | 0.28            |
| Run 26      | 0.30     | 0.31            |
| Run 27      | 0.26     | 0.38            |
| Run 28      | 0.24     | 0.39            |
| Run 29      | 0.18     | 0.37            |
| Run 30      | 0.19     | 0.51            |
| **Average** | 0.23     | 0.32            |

| 2^30        | C Kernel | Assembly Kernel |
|-------------|----------|-----------------|
| Run 01      | 2.445    | 9.526           |
| Run 02      | 1.683    | 2.722           |
| Run 03      | 1.661    | 1.931           |
| Run 04      | 1.461    | 1.917           |
| Run 05      | 1.187    | 1.957           |
| Run 06      | 1.165    | 1.949           |
| Run 07      | 1.47     | 2.34            |
| Run 08      | 1.79     | 2.103           |
| Run 09      | 1.42     | 2.222           |
| Run 10      | 1.87     | 2.157           |
| Run 11      | 1.174    | 1.960           |
| Run 12      | 1.248    | 1.945           |
| Run 13      | 1.133    | 1.952           |
| Run 14      | 1.72     | 1.969           |
| Run 15      | 1.103    | 1.933           |
| Run 16      | 1.56     | 1.952           |
| Run 17      | 1.129    | 2.18            |
| Run 18      | 1.123    | 2.95            |
| Run 19      | 1.344    | 2.28            |
| Run 20      | 1.283    | 2.81            |
| Run 21      | 1.462    | 2.328           |
| Run 22      | 1.142    | 1.943           |
| Run 23      | 1.85     | 1.989           |
| Run 24      | 1.39     | 1.919           |
| Run 25      | 1.60     | 2.2             |
| Run 26      | 1.53     | 1.937           |
| Run 27      | 1.107    | 1.966           |
| Run 28      | 1.283    | 1.922           |
| Run 29      | 1.291    | 1.950           |
| Run 30      | 1.116    | 1.944           |
| **Average** | 1.283    | 2.278           |

## Programs' Output
![image](https://github.com/Dwigoric/x86-c-interface/assets/30539952/00c6ff4a-772e-4812-84b6-a01820ba8c0d)

## Brief Performance Analysis
### Debug Mode
The performance of the kernels in debug mode followed our expectations: the C kernel had a longer time to execute than the Assembly kernel across all vector sizes. This is likely due to C having a more significant overhead with memory allocation and higher-level constructs. On the other hand, Assembly language avoids the compiler overhead and allows direct control over the hardware resources, allowing it to outperform C.

### Release Mode
The performance of the kernels in release mode was unexpected: the C kernel executed slightly faster than the Assembly kernel. This may be because the compiler optimizations implemented in release mode benefit the C kernel more than the Assembly kernel. In any case, the difference is miniscule, and further practice with Assembly may allow us to fine-tune the code better if the problem lies in not-so-efficient instructions.
