
#seta o tamanho da imagem
set terminal png size 1000,700

#legenda fora e superior direito
set key outside
set key right top

# nome do arquivo saida
set output './gnuplot/graficos/aceleracao_robo.png'
# titulo do grafico
set title 'Grafico da aceleracao do robo em funcao do tempo ate a interceptacao'

#nome do eixo x
set xlabel "Tempo (s)"
#nome do eixo y
set ylabel "Aceleração (m/s²)"

#plota as colunas 6 e 7 utilizando a coluna 1 (tempo) como eixo x
plot "gnuplot/data/dados_robo.txt" using 1:6 title 'Robo-aX' with lines,\
'' using 1:7  title 'Robo-aY' with lines