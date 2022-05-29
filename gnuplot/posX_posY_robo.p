






#seta o tamanho da imagem
set terminal png size 1000,700


#legenda fora e superior direito
set key outside
set key right top


# nome do arquivo saida
set output './gnuplot/graficos/deslocamento_robo.png'
# titulo do grafico
set title 'Grafico do deslocamento do robo em funcao do tempo até o instante interceptacao'

#nome do eixo x
set xlabel "Tempo (s)"
#nome do eixo y
set ylabel "Deslocamento (m)"

#plota as colunas 2 e 3, utilizando a coluna 1 (tempo) como eixo x
plot "gnuplot/data/dados_robo.txt" using 1:2 title 'RoboX' with lines,\
'' using 1:3  title 'RoboY' with lines