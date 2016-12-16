var ejemplo = ["A","N","A","B"];
var ocurr = ocurrencias(ejemplo);
console.log(ocurr);

//Ejemplo [“A”,”N”,”A”,”B”] => [{Nombre:”A”,Ocurrencia:2}
//{Nombre:”N”,Ocurrencia:1},{Nombre:”B”:Ocurrencia:1}]

function ocurrencias(arreglo){
	var distintos = obtenerDistintos(arreglo);
	var ocurr = [];
	for (var i = 0; i < distintos.length; i++){
		ocurr.push({Nombre: distintos[i], Ocurrencias: getCantidad(arreglo, distintos[i])});
	}
	return ocurr;
}

function obtenerDistintos(arreglo){
	var nodeSet = new Set(arreglo);
	return Array.from(nodeSet);
}

function getCantidad(arreglo, buscado){
	var cant = 0;
	for (var i = 0; i < arreglo.length; i++){
		if(arreglo[i] == buscado)
			cant++;
	}
	return cant;
}