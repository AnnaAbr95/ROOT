// e+ i e- a potem phi dzial dla przykladu a tutaj problem z masa
// przyklad zaczerpniety z http://zefir.if.uj.edu.pl/cbm/Docs/Pluto/html/pluto.html
//e- (510MeV) + E+ (510Mev) -> mezon phi (1020 MeV) - przykladowa reakcja z projektu FINUDA
//program wpada w nieskonczona petle
//roznica z reaction_4.C uzycie tutaj ustawienia poczatkowego SetDefault
R__LOAD_LIBRARY (/opt/pluto6/builddir/libPluto.so)
int reaction_3()
{ 	 	
PDecayChannel *c; 	
PDecayManager *pdm = new PDecayManager; 	
pdm->SetVerbose(1); 	// comment out to mute details
pdm->SetDefault("e-"); 	// enable desired decay channels
pdm->SetDefault("e+"); 	
pdm->SetDefault("phi"); 		
c = new PDecayChannel;
c->AddChannel(1.0, "e+", "e-", "phi"); 	// wejscie def
PParticle   *p = new PParticle("e+",0.51); 	// wiazka
PParticle *d = new PParticle("e-"); 	// tarcza
PParticle *s = new PParticle(*p + *d); 	// kwazi czastka
pdm->InitReaction(s,c); 	// reakcja
Int_t  n = pdm->loop(10000,0,"etap",0,0,1); 	// petla
cout << "Events processed: " << n << endl; 	// liczba zdarzen


return 0;
} 	
