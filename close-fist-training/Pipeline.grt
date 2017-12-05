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
NullRejectionThresholds:  19.0695 60.1338
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
OverallAverageTemplateLength: 40
***************TEMPLATE***************
Template: 1
ClassLabel: 1
TimeSeriesLength: 29
TemplateThreshold: 19.0695
TrainingMu: 16.8123
TrainingSigma: 5.64306
AverageTemplateLength: 32
TimeSeries: 
2.93033	-5.0337	-1.24699	
2.93033	-5.0337	-1.24699	
2.87787	-5.00593	-1.27322	
2.81383	-4.90562	-1.28942	
2.81383	-4.90562	-1.28942	
2.76907	-4.66875	-1.36427	
2.8416	-4.29839	-1.44374	
2.99515	-3.85319	-1.50624	
3.20887	-3.34858	-1.56256	
3.20887	-3.34858	-1.56256	
3.4496	-2.82777	-1.61812	
3.68262	-2.32779	-1.67598	
3.68262	-2.32779	-1.67598	
3.8948	-1.86561	-1.73385	
4.0769	-1.4559	-1.78786	
4.0769	-1.4559	-1.78786	
4.2235	-1.10406	-1.83724	
4.33306	-0.815495	-1.88122	
4.33306	-0.815495	-1.88122	
4.41099	-0.589423	-1.91826	
4.46731	-0.414275	-1.95375	
4.46731	-0.414275	-1.95375	
4.50204	-0.276935	-1.99619	
4.52132	-0.166599	-2.04017	
4.52132	-0.166599	-2.04017	
4.53444	-0.0732386	-2.08646	
4.53984	0.00700537	-2.12813	
4.53984	0.00700537	-2.12813	
4.54679	0.0741325	-2.17442	
***************TEMPLATE***************
Template: 2
ClassLabel: 2
TimeSeriesLength: 29
TemplateThreshold: 60.1338
TrainingMu: 45.4076
TrainingSigma: 36.8155
AverageTemplateLength: 49
TimeSeries: 
4.89708	-0.737566	-2.24155	
5.00973	-0.72985	-2.24309	
5.10772	-0.732936	-2.18677	
5.08535	-0.724449	-2.12273	
5.08535	-0.724449	-2.12273	
4.88937	-0.819353	-2.1181	
4.59308	-1.0408	-2.1559	
4.59308	-1.0408	-2.1559	
4.27905	-1.37257	-2.17596	
3.98585	-1.7846	-2.15899	
3.98585	-1.7846	-2.15899	
3.732	-2.22362	-2.11578	
3.53293	-2.66188	-2.04943	
3.53293	-2.66188	-2.04943	
3.38402	-3.07236	-1.96764	
3.27446	-3.44426	-1.87351	
3.27446	-3.44426	-1.87351	
3.18573	-3.76832	-1.7678	
3.1078	-4.04377	-1.65361	
3.1078	-4.04377	-1.65361	
3.03218	-4.27524	-1.53478	
2.9558	-4.46968	-1.41982	
2.9558	-4.46968	-1.41982	
2.88558	-4.62631	-1.31489	
2.82	-4.75131	-1.21998	
2.82	-4.75131	-1.21998	
2.72664	-4.93263	-1.06567	
2.72664	-4.93263	-1.06567	
2.7004	-4.99975	-1.01629	
PostProcessingModule_1
GRT_CLASS_LABEL_TIMEOUT_FILTER_FILE_V1.0
NumInputDimensions: 1
NumOutputDimensions: 1
FilterMode: 0
TimeoutDuration: 500
