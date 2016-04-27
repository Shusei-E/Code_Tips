# ggplot2

## Table of Contents
1. [xラベルの変更](#xラベルの変更)
2. [エラーバーの追加](#エラーバーの追加)

### xラベルの変更
```r
xlabels <- rep("", 120)
xlabels[c(seq(from = 1, to = 120, by = 10))] <- c(seq(from = 120, to = 1, by = -10))

g <- ggplot(data.frame(predicted=predicted, Date=date_vec, true_index=true_index), aes(x=reorder(Date, true_index), y=predicted)) + 
        geom_point() + xlab("Days to Election") + ylab("Prediction") +
        scale_x_discrete(labels = xlabels) +  # ここで変更を行なっている！
        theme_bw() 
options(repr.plot.width=6, repr.plot.height=2.8)
g
```
<img src="figures/ggplot2_xlab_changed.png" width="550">

### エラーバーの追加
##### その1
データ
```r
> res_mean <- apply(result_df, 2, mean)
> res_025 <- apply(result_df, 2, quantile, prob=.025)
> res_975 <- apply(result_df, 2, quantile, prob=.975)
> result <- data.frame(mean=res_mean, top=res_975, bottom=res_025)
> result$Date <- 1:120
> print(head(result))
       mean    top bottom Date
X1 341.3333 359.65 313.10    1
X2 350.3333 366.00 337.50    2
X3 343.3333 349.50 340.00    3
X4 366.3333 372.75 358.50    4
X5 341.3333 352.25 333.25    5
X6 347.6667 350.85 344.20    6
```
コード
```r
true_index <- 120:1  # 軸ラベルの調整用 (これをしないと、0スタートにソートされてしまう)

xlabels <- rep("", 120) # 適度に間隔の開いたラベルを作る
xlabels[c(seq(from = 1, to = 120, by = 10))] <- c(seq(from = 120, to = 1, by = -10))

g <- ggplot(result, aes(x=reorder(Date, true_index), y=mean, group=1)) + # reorderで指定した順序にする
        geom_line(size=0.8, color="blue") + xlab("Days to Election") + ylab("Prediction") +
        geom_errorbar(size=0.2, aes(ymin=bottom, ymax=top)) +
        geom_point(size=0.9, aes(x=reorder(Date, true_index), y=mean)) + # meanだけはpointを付ける
        geom_line(aes(x=reorder(Date, true_index), y=top), size=0.4, color="gray") + # 上を結ぶ
        geom_line(aes(x=reorder(Date, true_index), y=bottom), size=0.4, color="gray") + # 下を結ぶ
        scale_x_discrete(labels = xlabels) + # 軸ラベルを調整
        theme_bw() 
options(repr.plot.width=7, repr.plot.height=2.8)
g
```
<img src="figures/ggplot2_error_bars.png" width="580">