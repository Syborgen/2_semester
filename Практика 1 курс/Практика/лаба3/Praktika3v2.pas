unit Praktika3v2;

interface

uses
  Windows, Messages, SysUtils, Variants, Classes, Graphics, Controls, Forms,
  Dialogs, StdCtrls;

type
  TForm1 = class(TForm)
    Edit1: TEdit;
    Edit2: TEdit;
    Edit3: TEdit;
    Button1: TButton;
    Button2: TButton;
    Edit4: TEdit;
    Edit5: TEdit;
    Label1: TLabel;
    Label2: TLabel;
    Label3: TLabel;
    Label4: TLabel;
    Label5: TLabel;
    procedure Button1Click(Sender: TObject);
    procedure Button2Click(Sender: TObject);
  private
    { Private declarations }
  public
    { Public declarations }
  end;

  tconus=class
  lradius:integer;
  height:integer;
  ob:real;
  function v():real;
  virtual;
  constructor create(r: integer; h:integer);
  end;
  tslisedconus = class(tconus)
hradius:integer;
constructor create(lr,h,hr:integer);
function v():real;
override;
end;
var
  Form1: TForm1;

implementation

{$R *.dfm}

{tconus}

constructor tconus.create(r:integer;h:integer);
begin
lradius:=r;
height:=h;
end;

function tconus.v(): real;
begin
ob:=3.14*lradius*lradius*height*(1/3);
result:=ob;
end;





constructor tslisedconus.create(lr,h,hr:integer);
begin
inherited create(lr,h);
hradius:=hr;
end;

function tslisedconus.v():real;
begin
ob:=3.14*(lradius*lradius+lradius*hradius+hradius*hradius)*height*(1/3);
result:=ob;
end;






procedure TForm1.Button1Click(Sender: TObject);
var
conus: tconus;
i1,i2,i3:integer;
er1,er2,er3:boolean;
begin
i1:=strtointdef(Edit1.text,0);
if (i1<=0) then
  begin
  er1:=true;
  edit1.Clear;
  edit1.text:='Введите положительное число';
  end
  else begin er1:=false
   end;
 i2:=strtointdef(Edit2.text,0);
if (i2<=0) then
  begin
  er2:=true;
  edit2.Clear;
  edit2.text:='Введите положительное число';
  end
  else
  er2:=false;
  if(er1=true) or (er2=true) then
  showmessage('Невозможно найти объем')
  else
  begin
  conus:=tconus.create(i1,i2);
  edit4.Text:=floattostr(conus.v());
  end;
end;

procedure TForm1.Button2Click(Sender: TObject);
var
sconus:tslisedconus;
i1,i2,i3:integer;
er1,er2,er3:boolean;
begin
i1:=strtointdef(Edit1.text,0);
if (i1<=0) then
  begin
  er1:=true;
  edit1.Clear;
  edit1.text:='Введите положительное число';
  end
  else er1:=false;
  i2:=strtointdef(Edit2.text,0);
if (i2<=0) then
  begin
  er2:=true;
  edit2.Clear;
  edit2.text:='Введите положительное число';
  end
  else
  er2:=false;
  i3:=strtointdef(Edit3.text,0);
if (i3<=0) then
  begin
  er3:=true;
  edit3.Clear;
  edit3.text:='Введите положительное число';
  end
  else
  er3:=false;
  if(er1=true) or (er2=true) or (er3=true) then
  showmessage('Невозможно найти объем')
  else
  begin
  sconus:=tslisedconus.create(i1,i2,i3);
  edit5.Text:=floattostr(sconus.v());
  end;
end;
end.
