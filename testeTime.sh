######################################################################
# O conteúdo é livre para ser utilizados e editados, desde que citado 
# os autores originais e que seja utilizado para fins não comerciais.
#
# Desenvolvido por: Lucas Pereira Monteiro - lucasmonteiro@dcc.ufmg.br
# 				Jean Henrique Freire
# www.homepages.dcc.ufmg.br/~lucasmonteiro/
######################################################################

# Exclui o arquivo que já está preenchido e começa a preenche-lo novamente, com os novos dados de execução do programa
rm tempoExecucao.txt
# Executa o programa da seguinte forma:
# (seq x y z ) => "x" = valor inicial para "i", "y" = valor de incremento da variável "x" até chegar ao valor da variável "z"
#for i in $(seq 18 100 1000);
for i in 18 36 72 144 288 576 1152 2304 4608 9216 18432 36864 73728 147456
	do	
		# imprime o valor da variável "i" na tela
		echo $i 
		# "$i\t%E" 							=> string que será impressa no arquivo
		# tempoExecucao.txt 					=> arquivo que conterá a saída do medidas.sh
		# ./tp02.2 							=> executável
		# ./ARQ/sifts1000.txt ./ARQ/saida.txt $i	=> parâmetros de entrada (exemplo: passados por linha de comando)
		/usr/bin/time -f "$i\t%E" -a -o tempoExecucao.txt ./tp0 ./arq/$i.txt ./arq/saida.txt $i		
done

