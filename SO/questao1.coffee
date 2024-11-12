require './stdlib'

tableUsers = readlines './usuarios.yaml'
usersCount = len(tableUsers)

print 'Digite um usuário:'
newUser = input()

print 'Digite uma senha:'
newPassword = input_password('*')

usuarioExiste = false

if usersCount == 1 
  hashPass = hash_sha256(newPassword)
  tableUsers.add '{ '+newUser+','+hashPass+' }'
  writelines "usuarios.yaml", tableUsers
  print 'Novo usuário cadastrado com sucesso!'
else

  for i in [1...usersCount]
    aux = tableUsers[i].split(',')
    aux[0]=aux[0].replace('{ ','')
    aux[1]=aux[1].replace(' }','')
    if aux[0] == newUser
      print 'Este usuário já existe.'
      usuarioExiste = true
    break  


  if !usuarioExiste
    hashPass = hash_sha256(newPassword)
    tableUsers.add '{ '+newUser+','+hashPass+' }'
    writelines "usuarios.yaml", tableUsers
    print 'Novo usuário cadastrado com sucesso!'
