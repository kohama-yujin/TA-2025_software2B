# 出力形式をPNGに設定
set terminal pngcairo size 800,600 enhanced font 'Arial,10'

# 出力ファイル名
set output 'report4-3-N100-sigma3.0.png'

# タイトル・ラベルなど
set title "report4-3-graph"
set xlabel "x"
set ylabel "y"
set grid

# データとフィットした直線を描画
plot \
    "data_N100_sigma3.0.dat" with points, \
    (3*x + 4)/2 with lines lw 2 lc rgb "blue"

# 出力を閉じる
unset output