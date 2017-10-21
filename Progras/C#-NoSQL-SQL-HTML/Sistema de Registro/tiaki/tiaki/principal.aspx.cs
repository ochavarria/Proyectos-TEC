using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;

namespace tiaki
{
    public partial class principal : System.Web.UI.Page
    {
        protected void Page_Load(object sender, EventArgs e)
        {

        }

        protected void GridView1__RowDataBound(object sender, GridViewRowEventArgs e)
        {

            if (e.Row.RowType == DataControlRowType.DataRow)
            {
                string _estado = DataBinder.Eval(e.Row.DataItem, "Estado").ToString();

                if (_estado != "Activo")
                    e.Row.BackColor = System.Drawing.Color.Red;
                else
                    e.Row.BackColor = System.Drawing.Color.Green;

            }

        }
    }
}