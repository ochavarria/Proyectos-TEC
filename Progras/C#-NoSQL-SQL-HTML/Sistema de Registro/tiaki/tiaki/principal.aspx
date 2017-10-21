<%@ Page Language="C#" AutoEventWireup="true" CodeBehind="principal.aspx.cs" Inherits="tiaki.principal" %>

<!DOCTYPE html>
<script runat="server">

    void GridView5_RowDataBound(Object sender, GridViewRowEventArgs e)
    {

        if (e.Row.RowType == DataControlRowType.DataRow)
        {
            string _estado = DataBinder.Eval(e.Row.DataItem, "Estado").ToString();

            if (_estado != "Activo")
                for (int i = 0; i < 9; i++)
                {
                    e.Row.Cells[i].ForeColor =System.Drawing.Color.Red;
                }
            //e.Row.BackColor = System.Drawing.Color.Red;
            //e.Row.Attributes.Add("onmouseover", "this.style.backgroundColor='orange'");
            //e.Row.Attributes.CssStyle.Value = "background-color: DarkRed; color: White";
        }

    }

</script>
<html xmlns="http://www.w3.org/1999/xhtml">
<head>
    <meta charset="utf-8"/>
    <meta name="viewport" content="width=device-width, initial-scale=1"/>
    <link rel="stylesheet" href="https://maxcdn.bootstrapcdn.com/bootstrap/3.3.7/css/bootstrap.min.css"/>
    <script src="https://ajax.googleapis.com/ajax/libs/jquery/3.2.1/jquery.min.js"></script>
    <script src="https://maxcdn.bootstrapcdn.com/bootstrap/3.3.7/js/bootstrap.min.js"></script>
    <link rel="stylesheet" href="https://www.w3schools.com/w3css/4/w3.css" />
    <link rel="stylesheet" href="https://fonts.googleapis.com/css?family=Lato" />
    <link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/4.7.0/css/font-awesome.min.css" />
    <link rel="stylesheet" href="https://www.w3schools.com/lib/w3-theme-blue-grey.css" />
    <link rel='stylesheet' href='https://fonts.googleapis.com/css?family=Open+Sans' />
    <style>
    body {font-family: "Lato", sans-serif;}


    div.tab {
        overflow: hidden;
        border: 1px solid #ccc;
        background-color: #f1f1f1;
    }

    div.tab button {
        background-color: inherit;
        float: left;
        border: none;
        outline: none;
        cursor: pointer;
        padding: 14px 16px;
        transition: 0.3s;
        font-size: 17px;
    }

    div.tab button:hover {
        background-color: #ddd;
    }

    div.tab button.active {
        background-color: #ccc;
    }

    .tabcontent {
        display: none;
        padding: 6px 12px;
        border: 1px solid #ccc;
        border-top: none;
    }

    
    .topright {
        float: right;
        cursor: pointer;
        font-size: 20px;
    }

    .topright:hover {color: red;}
    html,body,h1,h2,h3,h4,h5 {font-family: "Open Sans", sans-serif}

 .gridview
{
    width: 100%;
    background-color: #fff;
    margin: 5px 0 10px 0;
    border: solid 1px #525252;
    border-collapse:collapse;
}
.gridview td
{
    padding: 2px;
    border: solid 1px #c1c1c1;
    color: #717171;
}
.gridview th
{
    padding: 4px 2px;
    color: #fff;
    background: #424242;
    border-left: solid 1px #525252;
    font-size: 0.9em;
}
.gridview .gridview_alter 
{
    background: #E7E7E7;
}
.gridview .gridview_pager 
{
    background: #424242;
}
.gridview .gridview_pager table 
{
    margin: 5px 0;
}
.gridview .gridview_pager td
{
    border-width: 0;
    padding: 0 6px;
    border-left: solid 1px #666;
    font-weight: bold;
    color: #fff;
    line-height: 12px;
 }  
.gridview .gridview_pager a 
{
    color: #666;
    text-decoration: none;
}
.gridview .gridview_pager a:hover 
{
    color: #000;
    text-decoration: none;
}
input:checked {
    height: 15px;
    width: 15px;
}
        .auto-style2 {
            position: relative;
            left: 0px;
            top: -1px;
        }
        .auto-style3 {
            padding: 0.01em 16px;
            width: 100%;
            height: 511px;
        }
        .auto-style4 {
            position: absolute;
            left: 50%;
            top: 0px;
            transform: translate(-50%,0%);
            -ms-transform: translate(-50%,0%);
        }
        .auto-style5 {
            position: absolute;
            right: 3px;
            top: -1px
        }
        </style>
</head>



<body >
<form id="form" runat="server">
<asp:ScriptManager ID="ScriptManager1" runat="server"></asp:ScriptManager>
<div class="container">
    <br />
    <div class="w3-container">
    <div class="w3-display-container">
        <div class="w3-padding w3-display-topleft"><img src="2.png" style="width:300px; height:50px;" /></div>
        <div class="w3-padding w3-display-right">
            <i class="glyphicon glyphicon-user"></i> <asp:Label ID="nombreAdministrador" runat="server" Text="Label"/><asp:Label ID="Label3" runat="server" Text="Label"/>  
            <asp:Button class="w3-button w3-white"  ID="Salir" runat="server"  Text="Cerrar sesión" />
            <asp:Label ID="Label1" runat="server" Text=""></asp:Label>
        </div>
    </div>
    </div>
    <br/>
    <br/>
    <br/>
    <br/>
  <ul class="nav nav-tabs">
    <li><a data-toggle="tab" href="#Tablero">Tablero de control</a></li>
    <li><a data-toggle="tab" href="#Nomina">Nomina</a></li>
    <li><a data-toggle="tab" href="#vigilantes">Vigilantes</a></li>
    <li><a data-toggle="tab" href="#residenciales">Residenciales</a></li>
  </ul>
    
   
  <div class="tab-content" >
    <div id="Tablero" class="tab-pane fade in active">
        <div class="w3-container"> 
            <div class="auto-style3">
            <br/>
                <div class="w3-row" style="height: 195px">
                     <div class="auto-style2">
                        <div class="w3-text-indigo">
                            <center>
                             <div class="w3-display-topleft">
                               <h3>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; Vigilantes&nbsp; activos&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; </h3>
                                <p>Hoy</p>
                                <p><script> document.write(new Date().toLocaleDateString()); </script></p>
                                <br />
                               <asp:GridView runat="server" ID="GridView3" AutoGenerateColumns="False" GridLines="None" AllowPaging="True" CssClass="gridview" PagerStyle-CssClass="gridview_pager" AlternatingRowStyle-CssClass="gridview_alter"
                                    PageSize="3" DataSourceID="SqlDataSource3">
                                    <AlternatingRowStyle CssClass="gridview_alter"></AlternatingRowStyle>
                                    <Columns>
                                       <asp:BoundField DataField="Nombre" HeaderText="Nombre" SortExpression="Nombre" />
                                       <asp:BoundField DataField="Apellidos" HeaderText="Apellidos" SortExpression="Apellidos" />
                                        <asp:BoundField DataField="Telefono" HeaderText="Telefono" SortExpression="Telefono" />
                                    </Columns>
                                    <PagerStyle CssClass="gridview_pager"></PagerStyle>
                               </asp:GridView>
                               <asp:SqlDataSource ID="SqlDataSource1" runat="server" ConnectionString="<%$ ConnectionStrings:TiakiConnectionString %>" SelectCommand="SELECT * FROM [Residenciales]" UpdateCommand="Update [Residenciales] Set [Nombre]=@Nombre, [Direccion]= @Direccion where [IdResidencial]=@IdResidencial" DeleteCommand="Delete from [Residenciales] where [IdResidencial]=@IdResidencial"></asp:SqlDataSource>
                            </div>
                            </center>
                            <center>
                               <div class="w3-display-topmiddle">
                               <h3>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; Proximo turno&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; </h3>
                               <p>Mañana</p>
                               <p><script> document.write(new Date().toLocaleDateString()); </script></p>
                               <br />
                               <asp:GridView runat="server" ID="GridView1" AutoGenerateColumns="False" GridLines="None" AllowPaging="True" CssClass="gridview" PagerStyle-CssClass="gridview_pager" AlternatingRowStyle-CssClass="gridview_alter"
                                    PageSize="3" DataSourceID="SqlDataSource3">
                                    <AlternatingRowStyle CssClass="gridview_alter"></AlternatingRowStyle>
                                    <Columns>
                                       <asp:BoundField DataField="Nombre" HeaderText="Nombre" SortExpression="Nombre" />
                                       <asp:BoundField DataField="Apellidos" HeaderText="Apellidos" SortExpression="Apellidos" />
                                        <asp:BoundField DataField="Telefono" HeaderText="Telefono" SortExpression="Telefono" />
                                    </Columns>
                                    <PagerStyle CssClass="gridview_pager"></PagerStyle>
                               </asp:GridView>
                            &nbsp;</div>
                            </center>
                            <center>
                               <div class="w3-display-topright">
                               <h3>Vigilantes para reemplazo</h3>
                               <br /><br /><br /><br />
                                <asp:GridView runat="server" ID="GridView2" AutoGenerateColumns="False" GridLines="None" AllowPaging="True" CssClass="gridview" PagerStyle-CssClass="gridview_pager" AlternatingRowStyle-CssClass="gridview_alter"
                                    PageSize="3" DataSourceID="SqlDataSource3">
                                    <AlternatingRowStyle CssClass="gridview_alter"></AlternatingRowStyle>
                                    <Columns>
                                       <asp:BoundField DataField="Nombre" HeaderText="Nombre" SortExpression="Nombre" />
                                       <asp:BoundField DataField="Apellidos" HeaderText="Apellidos" SortExpression="Apellidos" />
                                        <asp:BoundField DataField="Telefono" HeaderText="Telefono" SortExpression="Telefono" />
                                    </Columns>
                                    <PagerStyle CssClass="gridview_pager"></PagerStyle>
                               </asp:GridView>
                                   <asp:SqlDataSource ID="SqlDataSource3" runat="server" ConnectionString="<%$ ConnectionStrings:TiakiConnectionString %>" SelectCommand="SELECT [Nombre], [Apellidos], [Telefono] FROM [Vigilantes] WHERE ([idHorario] = @idHorario)">
                                       <SelectParameters>
                                           <asp:Parameter DefaultValue="g" Name="idHorario" Type="String" />
                                       </SelectParameters>
                                   </asp:SqlDataSource>
                                </div>
                            </center>
                      </div>
                    </div>
                   
                 </div>        
            </div>
        </div>
    </div>

    <div id="Nomina" class="tab-pane fade in active">
        <div class="w3-container">         
            
        </div>
    </div>

    <div id="vigilantes" class="tab-pane fade in active">
        <div class="w3-container">         
            <asp:UpdatePanel ID="UpdatePanel2" runat="server" updatemode="Conditional">
                <Triggers>
                <asp:AsyncPostBackTrigger ControlId="Timer1" /> 
            </Triggers>
            <ContentTemplate>
                <div class="auto-style3">
                    <br/>
                        <div class="w3-row" style="height: 195px">
                             <div class="auto-style2">
                                <div class="w3-text-indigo">
                                    <center>
                                     <div class="w3-display-toplmiddle">
                                         <h3>RUD Vigilantes</h3>
                                           <br /><br />
                                            <asp:GridView runat="server" ID="GridView5" AutoGenerateColumns="False" GridLines="None" AllowPaging="True" CssClass="gridview" PagerStyle-CssClass="gridview_pager" AlternatingRowStyle-CssClass="gridview_alter"
                                                PageSize="10" DataSourceID="SqlDataSource2" DataKeyNames="IdVigilante" AutoGenerateDeleteButton="True" AutoGenerateEditButton="True" OnRowDataBound="GridView5_RowDataBound">
                                                <AlternatingRowStyle CssClass="gridview_alter"></AlternatingRowStyle>
                                                <Columns>
                                                   <asp:BoundField DataField="IdVigilante" HeaderText="Id" SortExpression="IdVigilante" ReadOnly="True" />
                                                   <asp:BoundField DataField="Nombre" HeaderText="Nombre" SortExpression="Nombre" />
                                                    <asp:BoundField DataField="Apellidos" HeaderText="Apellidos" SortExpression="Apellidos" />
                                                    <asp:BoundField DataField="Estado" HeaderText="Estado" SortExpression="Estado" />
                                                    <asp:BoundField DataField="Edad" HeaderText="Edad" SortExpression="Edad" />
                                                    <asp:BoundField DataField="Telefono" HeaderText="Telefono" SortExpression="Telefono" />
                                                    <asp:BoundField DataField="idHorario" HeaderText="Horario" SortExpression="idHorario" />
                                                    <asp:BoundField DataField="idResidencial" HeaderText="Residencial" SortExpression="idResidencial" />
                                                </Columns>
                                                <PagerStyle CssClass="gridview_pager"></PagerStyle>
                                           </asp:GridView>
                                          <asp:timer ID="Timer1" runat="server" Interval="5000" ClientIDMode="AutoID"></asp:timer>
                                         <asp:SqlDataSource ID="SqlDataSource2" runat="server" ConflictDetection="CompareAllValues" ConnectionString="<%$ ConnectionStrings:TiakiConnectionString %>" DeleteCommand="DELETE FROM [Vigilantes] WHERE [IdVigilante] = @original_IdVigilante AND (([Nombre] = @original_Nombre) OR ([Nombre] IS NULL AND @original_Nombre IS NULL)) AND (([Apellidos] = @original_Apellidos) OR ([Apellidos] IS NULL AND @original_Apellidos IS NULL)) AND (([Estado] = @original_Estado) OR ([Estado] IS NULL AND @original_Estado IS NULL)) AND (([Edad] = @original_Edad) OR ([Edad] IS NULL AND @original_Edad IS NULL)) AND (([Telefono] = @original_Telefono) OR ([Telefono] IS NULL AND @original_Telefono IS NULL)) AND (([idHorario] = @original_idHorario) OR ([idHorario] IS NULL AND @original_idHorario IS NULL)) AND (([idResidencial] = @original_idResidencial) OR ([idResidencial] IS NULL AND @original_idResidencial IS NULL))" InsertCommand="INSERT INTO [Vigilantes] ([IdVigilante], [Nombre], [Apellidos], [Estado], [Edad], [Telefono], [idHorario], [idResidencial]) VALUES (@IdVigilante, @Nombre, @Apellidos, @Estado, @Edad, @Telefono, @idHorario, @idResidencial)" OldValuesParameterFormatString="original_{0}" SelectCommand="SELECT * FROM [Vigilantes]" UpdateCommand="UPDATE [Vigilantes] SET [Nombre] = @Nombre, [Apellidos] = @Apellidos, [Estado] = @Estado, [Edad] = @Edad, [Telefono] = @Telefono, [idHorario] = @idHorario, [idResidencial] = @idResidencial WHERE [IdVigilante] = @original_IdVigilante AND (([Nombre] = @original_Nombre) OR ([Nombre] IS NULL AND @original_Nombre IS NULL)) AND (([Apellidos] = @original_Apellidos) OR ([Apellidos] IS NULL AND @original_Apellidos IS NULL)) AND (([Estado] = @original_Estado) OR ([Estado] IS NULL AND @original_Estado IS NULL)) AND (([Edad] = @original_Edad) OR ([Edad] IS NULL AND @original_Edad IS NULL)) AND (([Telefono] = @original_Telefono) OR ([Telefono] IS NULL AND @original_Telefono IS NULL)) AND (([idHorario] = @original_idHorario) OR ([idHorario] IS NULL AND @original_idHorario IS NULL)) AND (([idResidencial] = @original_idResidencial) OR ([idResidencial] IS NULL AND @original_idResidencial IS NULL))">
                                             <DeleteParameters>
                                                 <asp:Parameter Name="original_IdVigilante" Type="Int32" />
                                                 <asp:Parameter Name="original_Nombre" Type="String" />
                                                 <asp:Parameter Name="original_Apellidos" Type="String" />
                                                 <asp:Parameter Name="original_Estado" Type="String" />
                                                 <asp:Parameter Name="original_Edad" Type="Int32" />
                                                 <asp:Parameter Name="original_Telefono" Type="Int32" />
                                                 <asp:Parameter Name="original_idHorario" Type="String" />
                                                 <asp:Parameter Name="original_idResidencial" Type="Int32" />
                                             </DeleteParameters>
                                             <InsertParameters>
                                                 <asp:Parameter Name="IdVigilante" Type="Int32" />
                                                 <asp:Parameter Name="Nombre" Type="String" />
                                                 <asp:Parameter Name="Apellidos" Type="String" />
                                                 <asp:Parameter Name="Estado" Type="String" />
                                                 <asp:Parameter Name="Edad" Type="Int32" />
                                                 <asp:Parameter Name="Telefono" Type="Int32" />
                                                 <asp:Parameter Name="idHorario" Type="String" />
                                                 <asp:Parameter Name="idResidencial" Type="Int32" />
                                             </InsertParameters>
                                             <UpdateParameters>
                                                 <asp:Parameter Name="Nombre" Type="String" />
                                                 <asp:Parameter Name="Apellidos" Type="String" />
                                                 <asp:Parameter Name="Estado" Type="String" />
                                                 <asp:Parameter Name="Edad" Type="Int32" />
                                                 <asp:Parameter Name="Telefono" Type="Int32" />
                                                 <asp:Parameter Name="idHorario" Type="String" />
                                                 <asp:Parameter Name="idResidencial" Type="Int32" />
                                                 <asp:Parameter Name="original_IdVigilante" Type="Int32" />
                                                 <asp:Parameter Name="original_Nombre" Type="String" />
                                                 <asp:Parameter Name="original_Apellidos" Type="String" />
                                                 <asp:Parameter Name="original_Estado" Type="String" />
                                                 <asp:Parameter Name="original_Edad" Type="Int32" />
                                                 <asp:Parameter Name="original_Telefono" Type="Int32" />
                                                 <asp:Parameter Name="original_idHorario" Type="String" />
                                                 <asp:Parameter Name="original_idResidencial" Type="Int32" />
                                             </UpdateParameters>
                                         </asp:SqlDataSource>
                                         
                                     </div>
                                    </center>
                                </div>
                            </div>
                        </div>
                </div>
            </ContentTemplate>
        </asp:UpdatePanel>
        </div>
    </div>
    <div id="residenciales" class="tab-pane fade in active">
        <div class="w3-container">         
            <asp:UpdatePanel ID="UpdatePanel1" runat="server" updatemode="Conditional">
            <ContentTemplate>
                <div class="auto-style3">
                    <br/>
                        <div class="w3-row" style="height: 195px">
                             <div class="auto-style2">
                                <div class="w3-text-indigo">
                                    <center>
                                     <div class="w3-display-toplmiddle">
                                         <h3>RUD residenciales</h3>
                                           <br /><br />
                                            <asp:GridView runat="server" ID="GridView4" AutoGenerateColumns="False" GridLines="None" AllowPaging="True" CssClass="gridview" PagerStyle-CssClass="gridview_pager" AlternatingRowStyle-CssClass="gridview_alter"
                                                PageSize="3" DataSourceID="SqlDataSource1" DataKeyNames="IdResidencial" AutoGenerateDeleteButton="True" AutoGenerateEditButton="True">
                                                <AlternatingRowStyle CssClass="gridview_alter"></AlternatingRowStyle>
                                                <Columns>
                                                   <asp:BoundField DataField="IdResidencial" HeaderText="Residencial" SortExpression="IdResidencial" ReadOnly="True" />
                                                   <asp:BoundField DataField="Nombre" HeaderText="Nombre" SortExpression="Nombre" />
                                                    <asp:BoundField DataField="Direccion" HeaderText="Direccion" SortExpression="Direccion" />
                                                </Columns>
                                                <PagerStyle CssClass="gridview_pager"></PagerStyle>
                                           </asp:GridView>
                                     </div>
                                    </center>
                                </div>
                            </div>
                        </div>
                </div>
            </ContentTemplate>
        </asp:UpdatePanel>
        </div>
    </div>
  </div>
</div>
</form>
</body>
</html>
