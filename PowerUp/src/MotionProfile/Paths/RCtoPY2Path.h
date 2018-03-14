#ifndef _RCTOPY2PATH_HG_
#define _RCTOPY2PATH_HG_

const int kRCtoPY2ProfileSz = 59;

const double kRCtoPY2ProfileLeft[][3] = {
		{0.003704, 0.148148, 50},
		{0.014388, 0.213678, 50},
		{0.032198, 0.356198, 50},
		{0.057139, 0.498821, 50},
		{0.089218, 0.641586, 50},
		{0.128445, 0.784536, 50},
		{0.174830, 0.927713, 50},
		{0.228388, 1.071157, 50},
		{0.289134, 1.214912, 50},
		{0.357085, 1.359018, 50},
		{0.432261, 1.503520, 50},
		{0.514684, 1.648459, 50},
		{0.604377, 1.793878, 50},
		{0.701368, 1.939820, 50},
		{0.805685, 2.086329, 50},
		{0.917357, 2.233446, 50},
		{1.036418, 2.381214, 50},
		{1.162902, 2.529676, 50},
		{1.296845, 2.678873, 50},
		{1.438288, 2.828848, 50},
		{1.587270, 2.979640, 50},
		{1.743834, 3.131292, 50},
		{1.908027, 3.283844, 50},
		{2.079893, 3.437337, 50},
		{2.259484, 3.591811, 50},
		{2.446849, 3.747308, 50},
		{2.642043, 3.903868, 50},
		{2.841422, 3.987594, 50},
		{3.041310, 3.997754, 50},
		{3.241706, 4.007914, 50},
		{3.440530, 3.976487, 50},
		{3.634034, 3.870067, 50},
		{3.820520, 3.729733, 50},
		{3.999938, 3.588359, 50},
		{4.172237, 3.445986, 50},
		{4.337370, 3.302653, 50},
		{4.495290, 3.158403, 50},
		{4.645954, 3.013276, 50},
		{4.789320, 2.867312, 50},
		{4.925347, 2.720553, 50},
		{5.053999, 2.573040, 50},
		{5.175240, 2.424815, 50},
		{5.289036, 2.275921, 50},
		{5.395356, 2.126399, 50},
		{5.494171, 1.976292, 50},
		{5.585453, 1.825643, 50},
		{5.669177, 1.674495, 50},
		{5.745322, 1.522890, 50},
		{5.813866, 1.370871, 50},
		{5.874790, 1.218482, 50},
		{5.928078, 1.065764, 50},
		{5.973716, 0.912759, 50},
		{6.011691, 0.759510, 50},
		{6.041994, 0.606057, 50},
		{6.064616, 0.452444, 50},
		{6.079552, 0.298709, 50},
		{6.086797, 0.144896, 50},
		{6.088496, 0.033987, 50},
		{6.088496, 0.000000, 50}
};

const double kRCtoPY2ProfileRight[][3] = {
		{0.003704, 0.148148, 50},
		{0.015242, 0.230766, 50},
		{0.034469, 0.384543, 50},
		{0.061380, 0.538216, 50},
		{0.095967, 0.691747, 50},
		{0.138222, 0.845093, 50},
		{0.188133, 0.998213, 50},
		{0.245686, 1.151065, 50},
		{0.310866, 1.303606, 50},
		{0.383656, 1.455796, 50},
		{0.464035, 1.607590, 50},
		{0.551983, 1.758947, 50},
		{0.647474, 1.909824, 50},
		{0.750483, 2.060177, 50},
		{0.860981, 2.209965, 50},
		{0.978938, 2.359144, 50},
		{1.104322, 2.507672, 50},
		{1.237097, 2.655506, 50},
		{1.377227, 2.802605, 50},
		{1.524674, 2.948927, 50},
		{1.679395, 3.094431, 50},
		{1.841349, 3.239076, 50},
		{2.010490, 3.382820, 50},
		{2.186771, 3.525624, 50},
		{2.370144, 3.667447, 50},
		{2.560556, 3.808247, 50},
		{2.757955, 3.947983, 50},
		{2.958575, 4.012406, 50},
		{3.158688, 4.002246, 50},
		{3.358292, 3.992086, 50},
		{3.555333, 3.940815, 50},
		{3.746152, 3.816388, 50},
		{3.929173, 3.660425, 50},
		{4.104448, 3.505502, 50},
		{4.272027, 3.351579, 50},
		{4.431958, 3.198614, 50},
		{4.584287, 3.046568, 50},
		{4.729057, 2.895399, 50},
		{4.866310, 2.745067, 50},
		{4.996086, 2.595529, 50},
		{5.118424, 2.446746, 50},
		{5.233357, 2.298675, 50},
		{5.340921, 2.151273, 50},
		{5.441146, 2.004499, 50},
		{5.534061, 1.858310, 50},
		{5.619695, 1.712663, 50},
		{5.698070, 1.567515, 50},
		{5.769212, 1.422824, 50},
		{5.833139, 1.278546, 50},
		{5.889871, 1.134640, 50},
		{5.939424, 0.991062, 50},
		{5.981813, 0.847770, 50},
		{6.017049, 0.704724, 50},
		{6.045143, 0.561880, 50},
		{6.066103, 0.419197, 50},
		{6.079934, 0.276635, 50},
		{6.086642, 0.134153, 50},
		{6.088215, 0.031463, 50},
		{6.088215, 0.000000, 50}
};

#endif
