using System;
using System.Net;
using System.Text;

namespace PneumoWorker
{
    internal class WorkerServer 
    {
        private HttpListener server;
        internal WorkerServer() 
        { 
            server = new HttpListener();
            server.Prefixes.Add("http://127.0.0.1:1992/workerctl");
        }

        internal void Start() { 
            server.Start();
        }
    }
}
