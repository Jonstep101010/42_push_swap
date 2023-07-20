while IFS= read -r line; do
    ../push_swap "$line" | ./checker_Mac "$line"
#../push_swap "$line" | wc -l

# while IFS= read -r line; do
#     ./push_swap "$line" | grep "(head)" | wc -l
done < test_100.csv