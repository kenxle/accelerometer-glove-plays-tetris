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
NumTrainingIterationsToConverge: 4941056
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
NullRejectionThresholds:  34.9532 39.9566
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
OverallAverageTemplateLength: 38
***************TEMPLATE***************
Template: 1
ClassLabel: 1
TimeSeriesLength: 36
TemplateThreshold: 34.9532
TrainingMu: 34.1892
TrainingSigma: 1.90991
AverageTemplateLength: 37
TimeSeries: 
-1.11358	-5.77637	-6.12384	
-1.82655	-5.58751	-6.10819	
-2.7675	-5.16621	-6.268	
-2.7675	-5.16621	-6.268	
-3.85484	-4.40071	-6.79435	
-4.90084	-3.24632	-7.72189	
-4.90084	-3.24632	-7.72189	
-5.69986	-1.78684	-8.89863	
-6.09099	-0.170912	-10.0642	
-6.09099	-0.170912	-10.0642	
-5.97365	1.38802	-10.9929	
-5.34785	2.7134	-11.5371	
-5.34785	2.7134	-11.5371	
-4.29179	3.69346	-11.7025	
-2.9396	4.2958	-11.5874	
-2.9396	4.2958	-11.5874	
-1.46559	4.54613	-11.2834	
-0.0329373	4.47796	-10.8431	
-0.0329373	4.47796	-10.8431	
1.21533	4.13711	-10.3212	
2.19763	3.56271	-9.74683	
2.19763	3.56271	-9.74683	
3.29391	1.91996	-8.50862	
3.29391	1.91996	-8.50862	
3.49283	0.964485	-7.9074	
3.54647	-0.00551957	-7.35199	
3.54647	-0.00551957	-7.35199	
3.51741	-0.940881	-6.87369	
3.45036	-1.80472	-6.48592	
3.45036	-1.80472	-6.48592	
3.37325	-2.57692	-6.19089	
3.30732	-3.23849	-5.98192	
3.30732	-3.23849	-5.98192	
3.26374	-3.79055	-5.83664	
3.24697	-4.2342	-5.73494	
3.24697	-4.2342	-5.73494	
***************TEMPLATE***************
Template: 2
ClassLabel: 2
TimeSeriesLength: 39
TemplateThreshold: 39.9566
TrainingMu: 36.4726
TrainingSigma: 8.70998
AverageTemplateLength: 39
TimeSeries: 
4.08288	-4.42865	-5.65448	
4.23821	-4.19174	-5.4768	
4.23821	-4.19174	-5.4768	
4.53771	-3.79837	-5.32258	
5.06629	-3.2005	-5.31141	
5.77256	-2.3713	-5.53826	
6.49895	-1.25155	-6.0255	
6.49895	-1.25155	-6.0255	
7.04094	0.159873	-6.76194	
7.19851	1.71434	-7.73753	
7.19851	1.71434	-7.73753	
6.84649	3.15482	-8.82711	
6.00053	4.22763	-9.78818	
6.00053	4.22763	-9.78818	
4.82267	4.78751	-10.3961	
3.50624	4.84227	-10.6263	
3.50624	4.84227	-10.6263	
2.20992	4.46343	-10.5872	
1.05776	3.76498	-10.3793	
1.05776	3.76498	-10.3793	
0.124633	2.86091	-10.0709	
-0.55817	1.85291	-9.69542	
-0.55817	1.85291	-9.69542	
-0.990649	0.819208	-9.28306	
-1.21303	-0.186557	-8.85282	
-1.21303	-0.186557	-8.85282	
-1.26221	-1.12192	-8.44045	
-1.18621	-1.97123	-8.06161	
-1.18621	-1.97123	-8.06161	
-0.846489	-3.36589	-7.4548	
-0.846489	-3.36589	-7.4548	
-0.648689	-3.91794	-7.22683	
-0.462064	-4.38395	-7.04914	
-0.298906	-4.75943	-6.90498	
-0.298906	-4.75943	-6.90498	
-0.150276	-5.05558	-6.791	
-0.0251146	-5.29249	-6.6893	
-0.0251146	-5.29249	-6.6893	
0.0765794	-5.47576	-6.59878	
PostProcessingModule_1
GRT_CLASS_LABEL_TIMEOUT_FILTER_FILE_V1.0
NumInputDimensions: 1
NumOutputDimensions: 1
FilterMode: 0
TimeoutDuration: 500
