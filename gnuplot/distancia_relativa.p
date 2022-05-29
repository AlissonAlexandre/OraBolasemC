#seta o tamanho da imagem
set terminal png size 1000,700


#legenda fora e superior direito
set key outside
set key right top

# nome do arquivo saida
set output './gnuplot/graficos/distancia_relativa.png'

# titulo do grafico
set title 'Grafico da distância relativa entre o robo e bola em funcao do tempo até o instante de interceptacao'

#nome do eixo x
set xlabel "Tempo (s)"
#nome do eixo y
set ylabel "Distancia (m)"


#plota a coluna 9, utilizando a coluna 1 (tempo) como eixo x
plot "gnuplot/data/dados_robo.txt" using 1:9 title 'Distancia' with lines

