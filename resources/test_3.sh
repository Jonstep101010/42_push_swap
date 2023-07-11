while IFS= read -r line; do
    ../push_swap "$line" | ./checker_Mac "$line"
# while IFS= read -r line; do
#     ./push_swap "$line" | grep "(head)" | wc -l
done < test_3.csv