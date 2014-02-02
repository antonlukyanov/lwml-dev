
function st()
  tm = os.clock()
end

function pt( msg )
  print(msg .. ': ' .. os.clock() - tm)
end

-- main

--[[
  COUNT(real ddd[M], ddd[j], "direct")
  COUNT(vector ddd(M), ddd[j], "vector")
  COUNT((void)0, rand(), "rand")
  COUNT(frand rnd, rnd.get_real(), "frand")

  COUNT(x1 xxx, xxx.get(j), "function")
  COUNT(x1 xxx, xxx[j], "operator")
  COUNT(x2 xxx, xxx.get(j), "virtual function")
  COUNT(x2 xxx, xxx[j], "virtual operator")

  COUNT(x1* xxx = new x1, xxx->get(j), "ptr function")
  COUNT(x1* xxx = new x1, (*xxx)[j], "ptr operator")
  COUNT(x2* xxx = new x2, xxx->get(j), "ptr virtual function")
  COUNT(x2* xxx = new x2, (*xxx)[j], "ptr virtual operator")
--]]

num = 1e6

x = 0.0
st()
for j = 1, num do
  x = x + math.sin(j/1e4)
end
pt('sin')

x = 0.0
st()
for j = 1, num do
  x = x + math.pow(j/1e4, j/1e6)
end
pt('pow')

x = 0.0
st()
for j = 1, num do
  x = x + math.exp(j/1e6* math.log(j/1e4))
end
pt('exp.log')

x = {}
for j = 1, num do
  x[j] = j
end

s = 0.0
st()
for j = 1, num do
  s = s + 2* x[j] + 1
end
pt('idx')

function fn(x) return 2*x+1 end
s = 0.0
st()
for j = 1, num do
  s = s + fn(x[j])
end
pt('fn')
