function rest=cofactor()
a=input('Ingrese la matriz de forma "[fila;fila;fila..;fila-n]" ');

%----------------------
if isempty(a)
    error(message('cof:EmptyMatrix'));
end

[r c] = size(a);    
m = ones(r,c);      
a_temp=a;           
for i = 1:r
    for k = 1:c
        a_temp([i],:)=[];   
        a_temp(:,[k])=[];   
        m(i,k) = ((-1)^(i+k))*det(a_temp);  
        a_temp=a;   
    end  
end
fprintf('Determinante de la matriz')
d=det(a);
d
pause
fprintf('Matriz de cofactores')
m  
pause
fprintf('Matriz de cofactores transpuesta')
mt=m';
mt
pause
disp('Division del determinante con la matriz trasp\n');
rest=1/d*mt;
rest


%return cofactor matrix as output variable

end