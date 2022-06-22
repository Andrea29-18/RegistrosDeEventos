class Evento{
	private:
		string nombreEvento;
		string encargado;
		string lugar;
		string fechaInicio;
		string duracion;
		string codigo;
	public:
		Evento(){
			nombreEvento = "";
		 	encargado = "";
			lugar = "";
			fechaInicio = "";
			duracion = "";
			codigo = generarCodigo();
		}

		Evento(string nuevoEvento, string encargadoEvento, string lugarEvento, string inciaEvento, string duracionEvento){
			nombreEvento = nuevoEvento ;
			encargado = encargadoEvento;
			lugar = lugarEvento;
			fechaInicio = inciaEvento;
			duracion = duracionEvento;
			codigo = generarCodigo();
		}

		void setNombreEvento(string nuevoEvento){
			nombreEvento = nuevoEvento ;
		}

		void setEncargado(string encargadoEvento){
	        encargado = encargadoEvento;
		}

		void setLugar(string lugarEvento){
			lugar = lugarEvento;
		}

		void setFechaInicio(string inciaEvento){
			fechaInicio = inciaEvento ;
		}

		void setDuracion(string duracionEvento){
			duracion = duracionEvento;
		}

		void setCodigo(string codigo01){
		    codigo = codigo01;
		}

		string getNombreEvento(){
			return nombreEvento;
		}

		string getEncargado(){
			return encargado;
		}

		string getLugar(){
		    return lugar;
		}

		string getFechaInicio(){
			return fechaInicio;
	    }

	    string getDuracion(){
	    	return duracion;
		}

		string getCodigo(){
			return codigo;
		}

	//Generar el codigo unico
    string generarCodigo(){
    	if(nombreEvento.size()>0){
	    	string codigo = "";
	    	codigo = codigo + nombreEvento[0];
	    	for(int i=0;i<nombreEvento.size();i++){
	    		if (nombreEvento[i]==' '){
	    			if (nombreEvento[i+1]!=' '){
	    				codigo = codigo + nombreEvento[i+1];
					}
			    }
			}
			return codigo;
		}else{
			return "";
		}

    }
};
