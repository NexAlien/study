source conf

if [ "$1" = "WK" ]
then
	AGE=$WK_AGE
elif [ "$1" = "BJ" ]
then
	AGE=$BJ_AGE
elif [ "$1" = "SS" ]
then
	AGE=$SS_AGE
else
	echo "No parameter given"
fi

echo $AGE
echo $EAPON  #���û�����,��ģ��AGE,���,�����ɹ���ʾ


#��ɮû�м����,�����,ʹ���������TS��ʱ���ܹ���ȷ��ʾ����
