{-
Desarrollar una función en Haskell donde reciba dos arreglos 
y indique si todos los elementos del primer arreglo existen en el 
segundo arreglo.
-}

quitarPrimero (a:b) = b

removerPosicionesIniciales [] _ = []
removerPosicionesIniciales arr pos = if pos > 0
                                then removerPosicionesIniciales (quitarPrimero arr) (pos -1)
                                else arr

searchChar _ [] _ = -1
searchChar x (a:b) y= if a == x
                        then y
                        else searchChar x b (y+1)


verificarSecuencia [] _ = True
verificarSecuencia _ [] = False
verificarSecuencia (a:b) (c:d) = if a == c
                                    then verificarSecuencia b d
                                    else False



existenEnA2 _ [] = True
existenEnA2 (a:b) array2 = if (searchChar a array2 0) > -1
                                then verificarSecuencia (a:b) (removerPosicionesIniciales array2 (searchChar a array2 0 ) ) 
                                else False

