//na bazie przykladu 2
//reakcja rozpadu hiperonu lambda -> n + pi0 -> g + g
R__LOAD_LIBRARY (/opt/pluto6/builddir/libPluto.so)


int lambda_npi_pigg () 
{
  PParticle lambda ("Lambda", 1.0 );                   
  PReaction *my_reaction = new PReaction (
                &lambda ,              
	        "n pi0 [g g]",   
        	"lambda_npi_pigg" ,

                1, 		
		0,               
                1,                
		0                                 
               );
    my_reaction->Print ();

    my_reaction->Loop (10000, 1);		 

    return 0;
}
