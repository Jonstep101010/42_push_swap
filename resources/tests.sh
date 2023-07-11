cd .. && make && cd ./resources
echo "test: 3"
sh ./test_3.sh | grep "KO"
echo "test: 4"
sh ./test_4.sh | grep "KO"
echo "test: 5"
sh ./test_5.sh | grep "KO"