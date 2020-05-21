// rozpad mezonu phi, reakcja zaczerpnieta z jednego z eksperymentow kolaboracji FINUDA
R__LOAD_LIBRARY (/opt/pluto6/builddir/libPluto.so)


int phi_kk () 
{
  PParticle phi ("phi", 1.5 );                  
   
  PReaction *my_reaction = new PReaction (
                &phi ,                 
	        "K+ K- [pi- pi0]",   
        	"phi_kk" ,   

                1, 		  
		0,               
                1,                
		0                                
               );
    my_reaction->Print ();

    my_reaction->Loop (10000, 1);		  

    return 0;
}
