//# general parameters
#define sim_time  100       //## time of simulation - 2 years in days
#define N 10000 //Number of Humans
#define NM 50000//Number of Mosquitos

//1.9 - 20000, 2.2- 50000, 2.8 - 100000


#define initial_latent 5

    //# mosquito lifetime parameters
#define winterlifespan_max 30
#define winterlifespan_min 1
#define summerlifespan_max 60
#define summerlifespan_min 1

    //# mosquito hazard function parameters
#define aSummer 0.0018;
#define bSummer 0.3228;
#define sSummer 2.1460;
#define aWinter 0.0018;
#define bWinter 0.8496;
#define sWinter 4.2920;

//# disease dynamics- human and mosquitos
#define h_latency_max 8
#define h_latency_min 4
#define m_latency_max 14
#define m_latency_min 7
#define h_symptomatic_max 6
#define h_symptomatic_min 3

#define ProbLatentToASymptomaticMax 0.8
#define ProbLatentToASymptomaticMin 0.4

#define m_lognormal_latent_shape 2.28 // ## mean 10
#define m_lognormal_latent_scale 0.21
#define h_lognormal_latent_shape 1.72 // ## mean 5.7
#define h_lognormal_latent_scale 0.21
#define h_lognormal_symptomatic_shape 1.54 // ## mean 4.7
#define h_lognormal_symptomatic_scale 0.12

#define prob_infection_MtoH 0.2851
#define prob_infection_HtoM 0.2851
#define ProbIsolationSymptomatic 0.1
#define reduction_factor 0.9

#define sextransMin 0.01
#define sextransMax 0.05

#define condom_reduction 0.0


//#define number_pregnant 150
#define Time_Preg_Max 270
#define Prob_Microcephaly_2_min 0.0028
#define Prob_Microcephaly_2_max 0.0132
#define Prob_Microcephaly_1_min 0.0038
#define Prob_Microcephaly_1_max 0.019


//#define Vac_Cover_Norm 0.0
//#define Vac_Cover_Preg 0.0
#define Time_of_immunization 0
#define Min_age_vac 9
#define Max_age_vac 60
#define Min_age_vac_preg 15
#define Max_age_vac_preg 50
#define vac_eff_min 0.7
#define vac_eff_max 0.9

#define previous_immunity 0.08

#define NR_END 1
