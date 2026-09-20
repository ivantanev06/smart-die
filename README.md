# Smart Die: Final-Face Prediction and Motion Reconstruction with Self-Attention



A physical smart die containing a Seeed Studio XIAO nRF52840 Sense

and its onboard LSM6DS3TR-C 6-axis IMU was constructed to investigate

what information about a die roll can be recovered from its motion.



The project investigates two questions:



1. How early before settling does the final face become predictable?

2. Can the chronological motion sequence be reconstructed from shuffled IMU states using a self-attention neural network?



## Dataset



1,000 physical die rolls were recorded.



Each IMU measurement contains

(ax, ay, az, wx, wy, wz)

corresponding to three-axis acceleration and angular velocity.



970 rolls contained enough pre-settling data for the prediction

and motion-sequence reconstruction analysis.



## Final-Face Prediction



Logistic regression, QDA and decision-tree classifiers were compared

with a physically motivated instantaneous-acceleration predictor.



## Motion Sequence Reconstruction



The final 300 ms before settling were resampled into 15 states.

The states were randomly shuffled and their acceleration and

angular-velocity vectors normalised to remove magnitude information.



A self-attention neural network, conditioned on the final face,

was trained to predict each state's relative position in the sequence.



On the held-out test set (146 rolls):



- Random pairwise baseline: 50%

- Mean pairwise ordering accuracy: 81.8%

- Mean Spearman rank correlation: 0.782



## Repository Structure



- `data/raw/` — raw IMU measurements

- `data/metadata/` — roll metadata and final faces

- `analysis/` — Python notebook containing the statistical and ML analysis

- `arduino/` — code used to collect measurements from the smart die

- `poster/` — final project poster



## Authors



Ivan Tanev

Department of Mathematics, Imperial College London
