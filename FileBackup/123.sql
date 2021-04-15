do $$
DECLARE var1 integer;
DECLARE var2 integer;
begin
var:=0;
for i in 33..127 loop
for j in 33..127 loop
INSERT INTO public.two_char_c(x, y, z, t, two_char_c) VALUES (2,0,var,timeofday(),CONCAT(chr(i),chr(j))
var := var+1;
end loop;
end loop;
end;
$$;