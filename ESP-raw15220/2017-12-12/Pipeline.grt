GRT_PIPELINE_FILE_V3.0
PipelineMode: CLASSIFICATION_MODE
NumPreprocessingModules: 0
NumFeatureExtractionModules: 0
NumPostprocessingModules: 1
Trained: 1
Info: 
PreProcessingModuleDatatypes:
FeatureExtractionModuleDatatypes:
ClassificationModuleDatatype:	DTW
PostProcessingModuleDatatypes:	ClassLabelTimeoutFilter
GRT_DTW_Model_File_V2.0
Trained: 1
UseScaling: 0
NumInputDimensions: 3
NumOutputDimensions: 1
NumTrainingIterationsToConverge: 48
MinNumEpochs: 0
MaxNumEpochs: 100
ValidationSetSize: 20
LearningRate: 0.1
MinChange: 1e-05
UseValidationSet: 0
RandomiseTrainingOrder: 1
UseNullRejection: 1
ClassifierMode: 1
NullRejectionCoeff: 0.4
NumClasses: 2
NullRejectionThresholds:  10.8199 0
ClassLabels:  1 2
DistanceMethod: 1
UseSmoothing: 0
SmoothingFactor: 5
UseZNormalisation: 0
OffsetUsingFirstSample: 0
ConstrainWarpingPath: 1
Radius: 0.2
RejectionMode: 0
NumberOfTemplates: 2
OverallAverageTemplateLength: 60
***************TEMPLATE***************
Template: 1
ClassLabel: 1
TimeSeriesLength: 65
TemplateThreshold: 10.8199
TrainingMu: 9.63978
TrainingSigma: 2.9502
AverageTemplateLength: 62
TimeSeries: 
-0.891269	-0.484804	-0.0901962	
-0.901525	-0.471514	-0.0524942	
-0.948472	-0.48307	-0.0880295	
-0.98213	-0.499394	-0.166756	
-0.979096	-0.486104	-0.185101	
-0.95425	-0.483937	-0.196224	
-0.861079	-0.519906	-0.393979	
-0.825688	-0.550385	-0.564144	
-0.619554	-0.574509	-0.735609	
-0.397531	-0.583176	-1.11003	
-0.475824	-0.0588141	-2.05532	
-1.09711	0.564064	-2.43928	
-1.59128	1.35956	-2.40952	
-1.91674	1.92365	-1.97573	
-2.0947	2.16373	-1.37452	
-2.01655	2.15188	-0.678695	
-1.78471	1.97132	-0.0415158	
-1.65138	1.71289	0.53716	
-1.54824	1.4653	1.15585	
-1.31177	1.13393	1.67371	
-1.21166	1.10056	1.50268	
-1.09379	1.06907	1.14588	
-1.05768	1.03859	0.839354	
-1.07082	0.956685	0.597685	
-1.09018	0.838234	0.464212	
-1.13063	0.674715	0.274401	
-1.23015	0.484182	0.0564228	
-1.33026	0.300439	-0.0800846	
-1.3408	0.145008	-0.196224	
-1.29256	0.0911273	-0.272062	
-1.11113	-0.18001	-0.50333	
-0.969851	-0.253969	-0.519942	
-0.833199	-0.333129	-0.512575	
-0.774263	-0.397844	-0.490907	
-0.77354	-0.436701	-0.419981	
-0.813554	-0.425434	-0.342843	
-0.898203	-0.490726	-0.286074	
-0.951939	-0.504016	-0.268306	
-0.995708	-0.494627	-0.234504	
-0.993108	-0.442768	-0.139166	
-0.968407	-0.423267	-0.0413714	
-0.971007	-0.480904	-0.034871	
-0.989785	-0.492315	-0.117498	
-0.966529	-0.470359	-0.0978522	
-0.935183	-0.457069	-0.0686729	
-0.940816	-0.495204	-0.106519	
-0.942838	-0.489426	-0.148988	
-0.938216	-0.508927	-0.191746	
-0.906581	-0.491882	-0.177012	
-0.887658	-0.435401	-0.11042	
-0.876246	-0.441902	-0.053072	
-0.904125	-0.48047	-0.0764733	
-0.932438	-0.503727	-0.125154	
-0.926226	-0.511816	-0.171812	
-0.901814	-0.497516	-0.121542	
-0.896325	-0.508061	-0.106086	
-0.916115	-0.525973	-0.114031	
-0.904992	-0.51355	-0.11302	
-0.903981	-0.506183	-0.0777734	
-0.926515	-0.507483	-0.0913519	
-0.934316	-0.50835	-0.110997	
-0.938938	-0.479892	-0.0938076	
-0.936483	-0.504594	-0.0532165	
-0.911348	-0.506616	-0.0650616	
-0.925071	-0.484659	-0.0779178	
***************TEMPLATE***************
Template: 2
ClassLabel: 2
TimeSeriesLength: 52
TemplateThreshold: 0
TrainingMu: 0
TrainingSigma: 0
AverageTemplateLength: 58
TimeSeries: 
-0.796508	-0.46747	-0.133676	
-0.804164	-0.478448	-0.130643	
-0.808931	-0.473537	-0.128765	
-0.817454	-0.453313	-0.127609	
-0.811098	-0.464147	-0.127032	
-0.824532	-0.482348	-0.115042	
-0.810954	-0.46617	-0.086296	
-0.81861	-0.448835	-0.0386268	
-0.823376	-0.455769	0.0188652	
-0.831899	-0.442624	0.128504	
-0.813987	-0.394232	0.298236	
-0.907159	-0.336307	0.47519	
-1.07285	-0.238079	0.67959	
-1.38024	-0.155886	0.767561	
-1.78427	-0.0604031	0.687535	
-2.18383	0.294661	0.247678	
-1.96022	0.492994	0.0577229	
-1.64112	0.531129	-0.322042	
-1.16082	0.415278	-0.827192	
-0.589508	0.18401	-1.14181	
-0.0618241	-0.0702258	-1.24971	
0.405046	-0.188099	-1.1239	
0.488684	-0.35133	-0.973233	
0.278939	-0.460825	-0.830803	
-0.149073	-0.601666	-1.01671	
0.0465151	-0.483937	-1.09371	
0.192701	-0.280404	-1.20363	
0.164822	0.0382578	-1.35618	
-0.0888367	0.431601	-1.4245	
-0.529849	0.806311	-1.33277	
-1.0025	1.04841	-1.13892	
-1.47096	1.07817	-0.872405	
-2.17386	0.742752	-0.197091	
-2.21994	0.588477	0.206942	
-2.07433	0.392021	0.426221	
-1.81937	0.216223	0.39603	
-1.55084	0.0704707	0.250711	
-1.32044	-0.057514	0.0711569	
-1.08397	-0.151697	-0.0539387	
-0.918859	-0.213956	-0.11172	
-0.739016	-0.257003	-0.146244	
-0.599909	-0.351619	-0.202725	
-0.59962	-0.403188	-0.200847	
-0.6457	-0.434101	-0.136277	
-0.713737	-0.418067	-0.074451	
-0.783508	-0.391054	-0.00265817	
-0.880435	-0.38022	0.0166984	
-0.880435	-0.38022	0.0166984	
-0.862234	-0.353208	-0.0699729	
-0.765596	-0.356097	-0.127754	
-0.710559	-0.359708	-0.127032	
-0.735405	-0.379209	-0.143932	
PostProcessingModule_1
GRT_CLASS_LABEL_TIMEOUT_FILTER_FILE_V1.0
NumInputDimensions: 1
NumOutputDimensions: 1
FilterMode: 0
TimeoutDuration: 500