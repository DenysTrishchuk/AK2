#include <stdio.h>
#include <unistd.h>
#include <map>
#include <string>
#include <getopt.h>

using namespace std;

int main(int argc, char *argv[]){
    int result = 0;
    map <string, bool> used;
    int option_index = -1;
    const char* short_options = "hlvtfsV::";
    const struct option long_options[] = {{"help", 0, NULL, 'h'},
    					   {"list", 0, NULL, 'l'},
    					   {"version", 0, NULL, 'v'},
    					   {"two", 0, NULL, 't'},
    					   {"four", 0, NULL, 'f'},
    					   {"six", 0, NULL, 's'},
    					   {"value", 2, NULL, 'V'},
    					   {NULL, 0, NULL, 0}
    };

    while ((result = getopt_long(argc,argv,short_options,long_options, &option_index)) != -1) { 
        switch (result){
            case 'h': {
                if (used["h"] == false) {
                    printf("Arg: Help\n");
                    used["h"] = true;
                    break;
                } 
		break;
	    }
	    
            case 'l': {
                if (used["l"] == false) {
                    printf("Arg: List\n"); 
		     used["l"] = true;
		     break;
		}
		break;
	    }
	    
            case 'v': {
                if (used["v"] == false) {
                    printf("Arg: Version\n"); 
		     used["v"] = true;
		     break;
		}
		break;
	    }
	    
	     case 't': {
                if (used["t"] == false) {
                    printf("Arg: Two\n"); 
		     used["t"] = true;
		     break;
		}
		break;
	    }
	    
            case 'f': {
                if (used["f"] == false) {
                    printf("Arg: Four\n"); 
		     used["f"] = true;
		     break;
		}
		break;
	    }
	    
            case 's': {
                if (used["s"] == false) {
                    printf("Arg: Six\n"); 
		     used["s"] = true;
		     break;
		}
		break;
	    }
	    
            case '?': default: {
                printf("Key %c isn't found\n", result);
                break;
            }
            
	    case 'V': {
	        if (used["V"] == false) {
	            if (optarg == NULL) {
	                printf("Arg: Value without params\n"); 
	                used["V"] = true;
		     } else {
		         printf("Arg: Value = %s\n", optarg); 
		         used["V"] = true;
		     }
		     break;
		}
		break;
	     }
        }
	option_index = -1;
    }
}
