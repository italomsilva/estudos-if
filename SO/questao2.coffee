require './stdlib'

tableUsers = readlines "usuarios.yaml"
lineCount = len(tableUsers)

print 'Usuário'
userInput = input()
print 'Senha:'
passInput = input_password('*')
passInput = hash_sha256(passInput)
login=false

for i in [1...lineCount]
  aux = tableUsers[i].split(',')
  aux[0]=aux[0].replace('{ ','')
  aux[1]=aux[1].replace(' }','')
  if aux[0] == userInput && aux[1] == passInput
    login=true
  break
if login == true
  print 'Bem Vindo '+userInput
else
  print 'Usuário ou senha inválida'