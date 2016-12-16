#import numpy #pip install numpy
#sudoku = numpy.zeros((9,9))

def checkFila(arreglo, fila):
	arr = []
	for n in range(9):
		arr.append(arreglo[n][fila])
	
	#print arr

	arr.sort()
	for n in range(9):
		if arr[n] != n+1:
			return False
	return True

def checkFilas(arreglo):
	for n in range(9):
		if checkFila(arreglo, n) == False:
			print "Fallo en fila: ", n
			return False
	return True

def checkColumna(arreglo, col):
	arr = []
	for n in range(9):
		arr.append(arreglo[col][n])
	
	#print arr

	arr.sort()
	for n in range(9):
		if arr[n] != n+1:
			return False
	return True

def checkColumnas(arreglo):
	for n in range(9):
		if checkColumna(arreglo, n) == False:
			print "Fallo en columna: ", n
			return False
	return True

def checkCuadrante(arreglo, cuad):
	x = (cuad%3) *3
	y = (cuad/3) * 3

	arr = []
	#print "x: ", x, "y: ", y

	for col in range(x, x+3):
		for fila in range(y, y+3):
			arr.append(arreglo[fila][col])

	#print arr

	arr.sort()

	for n in range(9):
		if arr[n] != n+1:
			return False
	return True	


# def checkCuadrante(arreglo, cuad):
# 	x = cuad*3
# 	y = cuad*3
# 	ocurrencias = [False]*9
# 	for n in range(x, x+3):
# 		for m in range(y, y+3):
# 			numero = arreglo[n][m]
# 			print numero
# 			if ocurrencias[numero-1]:
# 				return False 
# 			ocurrencias[numero-1] = True;
# 	print ocurrencias
# 	return True;

def checkCuadrantes(arreglo):
	for n in range(9):
		if checkCuadrante(arreglo, n) == False:
			print "fallo en cuadrante: ", n
			return False
	return True





#sudoku = [[0]*9 for i in range(9)]
sudoku = [
	[9,6,3,1,7,4,2,5,8],
	[1,7,8,3,2,5,6,4,9],
	[2,5,4,6,8,9,7,3,1],
	[8,2,1,4,3,7,5,9,6],
	[4,9,6,8,5,2,3,1,7],
	[7,3,5,9,6,1,8,2,4],
	[5,8,9,7,1,3,4,6,2],
	[3,1,7,2,4,6,9,8,5],
	[6,4,2,5,9,8,1,7,3]
]

# for n in range(1,10):
# 	for m in range(1,10):
# 		sudoku[n-1][m-1] = m

for n in range(9):
	print sudoku[n]

print
cf = checkFilas(sudoku)
print
cc = checkColumnas(sudoku)
print
cs = checkCuadrantes(sudoku)

# print
# print "CheckFila: ", cf
# print 
# print "CheckColumna: ", cc
# print
# print "CheckCuadrantes: ", cs

if cf and cc and cs:
	print "Sudoku esta bien"
else:
	print "Sudoku esta mal"
