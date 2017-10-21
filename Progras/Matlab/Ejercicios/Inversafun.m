function []= Inversafun()
Matriz= input('Ingrese la matriz de forma "[fila;fila;fila..;fila-n]" ');

f=size(Matriz);
f=f(1);
c=size(Matriz);
c=c(2);  

b=Matriz;
if(det(Matriz)~=0)
M=b;
M
if (c==f)
for k=1:c
  for j=1:f
    if j~=k
        a(j,k)=0;
        j=j+1;
        
    else
        a(j,k)=1;
        j=j+1;
    end
  end
  k=k+1;
end
a=[b a];
M=a;
M
pause 
for k=1:c
  a(k,:)=a(k,:)/a(k,k);
   for j=k+1:f
    a(j,:)=a(j,:)-a(k,:)*a(j,k);
    j=j+1;
    M=a;
    M
    pause
  end
  k=k+1;
  pause
end


for k=f:-1:2
  for j=k-1:-1:1
    a(j,:)=a(j,:)-a(k,:)*a(j,k);
    j=j-1;
    M=a;
    M
    pause
  end
  k=k-1;
  pause
end
c=inv(b);
Fin=c;
Fin
else
fprintf('La matriz tiene que ser de NxN')
end
else
    fprintf('La matriz es singularo osea no es invertible')
end
end