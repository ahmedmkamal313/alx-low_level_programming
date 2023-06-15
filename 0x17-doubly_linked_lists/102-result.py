# Define a function to check if a number is a palindrome
def is_palindrome(n):
  # Convert the number to a string
  s = str(n)
  # Compare the string with its reverse
  return s == s[::-1]

# Initialize the largest palindrome and the factors
largest = 0
factor1 = 0
factor2 = 0

# Loop through all possible pairs of three-digit numbers
for i in range(100, 1000):
  for j in range(i, 1000):
    # Calculate the product
    product = i * j
    # Check if it is a palindrome and larger than the current largest
    if is_palindrome(product) and product > largest:
      # Update the largest and the factors
      largest = product
      factor1 = i
      factor2 = j

# Print the result and the factors
print(largest)
print(factor1, factor2)

# Save the result in the file 102-result
with open("102-result", "w") as f:
  f.write(str(largest))
