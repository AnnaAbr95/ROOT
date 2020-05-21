// dla przykladu z ktorego czerpalam http://zefir.if.uj.edu.pl/cbm/Docs/Pluto/html/pluto.html makro dziala, w przypadku mojej reakcji, czyli e- (510MeV) + E+ (510Mev) -> mezon phi (1020 MeV) - przykladowa reakcja z projektu FINUDA
//problem z masa/energia, program wpada w nieskonczona petle
// 
R__LOAD_LIBRARY (/opt/pluto6/builddir/libPluto.so)
int reaction_4()
{
PParticle p1("e+",0.51);
PParticle p2("e-");
PParticle q=p1+p2;
PDecayChannel*c = new PDecayChannel;
PDecayManager*pdm = new PDecayManager;

c->AddChannel(1.0,"e+","e-","phi");



PDecayChannel * ee_reaction = new PDecayChannel;
ee_reaction->AddChannel(1.0,"K+","K-");
pdm->AddChannel("phi",ee_reaction);


pdm->InitReaction(&q,c);pdm->loop(100000,0,"phi_sample",1,0,0,1,1);

return 0;
}
