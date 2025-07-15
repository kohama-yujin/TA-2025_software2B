# 出力形式をPNGに設定
set terminal pngcairo size 800,600 enhanced font 'Arial,10'

# 出力ファイル名
set output 'report4-4-fix-N100-sigma2.0.png'

# タイトル・ラベルなど
set title "report4-4-fix-graph"
set xlabel "x"
set ylabel "y"
set grid

# データとフィットした直線を描画
plot \
    "../report4_3/data_N100_sigma2.0.dat" with points, \
    1.35415 * x + 2.08308 with lines lw 2 lc rgb "blue"

# 出力を閉じる
unset output