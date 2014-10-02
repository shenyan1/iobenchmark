#提取trace文件中想要的信息
cat usr_1.csv | awk -F"," '{if($4=="Write") print "W",$5,$6;else print "R",$5,$6}'> ~/usr_1_ssd.csv
