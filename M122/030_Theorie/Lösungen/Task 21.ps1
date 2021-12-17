# Variante a)
#Get-ChildItem * -include *.jpg  | measure-object length  -sum

# Variante b)
(Get-ChildItem * -include *.jpg| measure-object length -sum).sum