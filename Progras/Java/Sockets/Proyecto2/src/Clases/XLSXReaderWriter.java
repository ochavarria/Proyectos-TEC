/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package Clases;

import java.io.File;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.IOException;
import java.sql.Date;
import java.text.DateFormat;
import java.text.SimpleDateFormat;
import java.util.ArrayList;
import java.util.Calendar;
import java.util.HashMap;
import java.util.Iterator;
import java.util.Map;
import java.util.Set;
import org.apache.poi.hssf.usermodel.HSSFDateUtil;

import org.apache.poi.ss.usermodel.Cell;
import org.apache.poi.ss.usermodel.Row;
import org.apache.poi.xssf.usermodel.XSSFSheet;
import org.apache.poi.xssf.usermodel.XSSFWorkbook;

/**
 * Sample Java program to read and write Excel file in Java using Apache POI
 *
 */
public class XLSXReaderWriter {
    public ArrayList  Read(String Path)
    {
        ArrayList<ArrayList> Tickets=new ArrayList<ArrayList>();
        
        try {
            File excel = new File(Path);
            FileInputStream fis = new FileInputStream(excel);
            XSSFWorkbook book = new XSSFWorkbook(fis);
            XSSFSheet sheet = book.getSheetAt(0);

            Iterator<Row> itr = sheet.iterator();
            
            // Iterating over Excel file in Java
            while (itr.hasNext()) {
                Row row = itr.next();
                ArrayList<String>Ticket=new ArrayList<String>();
                // Iterating over each column of Excel file
                Iterator<Cell> cellIterator = row.cellIterator();
                while (cellIterator.hasNext()) {

                    Cell cell = cellIterator.next();

                    switch (cell.getCellType()) {
                    case Cell.CELL_TYPE_STRING:
                        Ticket.add(cell.getStringCellValue());
                        
                        break;
                    case Cell.CELL_TYPE_NUMERIC:
                         if (HSSFDateUtil.isCellDateFormatted(cell))
                         {

                             DateFormat df = new SimpleDateFormat("MM/dd/yyyy HH:mm:ss");
                             java.util.Date date = cell.getDateCellValue();
                             String reportDate = df.format(date);
                             
                             
                             //double fecha=cell.getNumericCellValue();
                             
                             
                             Ticket.add(reportDate);
                             
                         }
                         else
                         {
                             Ticket.add(cell.getStringCellValue());
                             
                         }
                        break;
                    case Cell.CELL_TYPE_BLANK:
                        break;
                    default:

                    }
                }
                Tickets.add(Ticket);
               
            }
            return Tickets;
        }
        catch (FileNotFoundException fe) 
        {
            fe.printStackTrace();
        } 
        catch (IOException ie) 
        {
            ie.printStackTrace();
        }
        return null;
}
    public void Write(String path) {

        try {
            File excel = new File(path);
            FileInputStream fis = new FileInputStream(excel);
            XSSFWorkbook book = new XSSFWorkbook(fis);
            XSSFSheet sheet = book.getSheetAt(2);

            Iterator<Row> itr = sheet.iterator();

            // writing data into XLSX file
            Map<String, Object[]> newData = new HashMap<String, Object[]>();
            newData.put("7", new Object[] { 7d, "Sonya", "75K", "SALES",
                    "Rupert" });
            newData.put("8", new Object[] { 8d, "Kris", "85K", "SALES",
                    "Rupert" });
            newData.put("9", new Object[] { 9d, "Dave", "90K", "SALES",
                    "Rupert" });

            Set<String> newRows = newData.keySet();
            int rownum = sheet.getLastRowNum();

            for (String key : newRows) {
                Row row = sheet.createRow(rownum++);
                Object[] objArr = newData.get(key);
                int cellnum = 0;
                for (Object obj : objArr) {
                    Cell cell = row.createCell(cellnum++);
                    if (obj instanceof String) {
                        cell.setCellValue((String) obj);
                    } else if (obj instanceof Boolean) {
                        cell.setCellValue((Boolean) obj);
                    } else if (obj instanceof Date) {
                        cell.setCellValue((Date) obj);
                    } else if (obj instanceof Double) {
                        cell.setCellValue((Double) obj);
                    }
                }
            }

            // open an OutputStream to save written data into Excel file
            FileOutputStream os = new FileOutputStream(excel);
            book.write(os);
            System.out.println("Writing on Excel file Finished ...");

            // Close workbook, OutputStream and Excel file to prevent leak
            os.close();
            book.close();
            fis.close();

        } catch (FileNotFoundException fe) {
            fe.printStackTrace();
        } catch (IOException ie) {
            ie.printStackTrace();
        }
    }
}