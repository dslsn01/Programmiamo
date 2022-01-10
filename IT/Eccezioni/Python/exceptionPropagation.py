# file exceptionPropagation.py 

from __future__ import print_function

# la funzione propagate() solleva un'eccezione generica 

def propagate(): 
	raise Exception("Sollevata un'eccezione!") 

# la funzione chiamante caller() invoca la funzione propagate() e gestisce l'eccezione

def caller(): 
	try: 
		propagate() 

	except Exception as e: 
		print(str(e))

# invoca la funzione caller() 

caller() 

print("Fine del programma.")

