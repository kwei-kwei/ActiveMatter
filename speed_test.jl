# Import the library
using Random
  
# Using the MersenneTwister rng
# Here 1234 is a seed value

# Generate random data
x = rand(rng, 10_000_000);
 
# a function that considers
# x as a global variable
function prod_global()
    prod = 0.0
    for i in x
       prod *= i
    end
    return prod
end;
 
# a function that accepts
# x as a local variable
function prod_local(x)
    prod = 0.0
    for i in x
       prod *= i
    end
    return prod
end;

@time prod_local(x)
