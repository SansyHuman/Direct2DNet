using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.IO;
using D2DNet.Direct2DNet;
using System.Text.Json;
using System.Xml;

namespace D2DNet.Direct2DNet.Extensions
{
    public static class D2D1MeshBuilder
    {
        public struct CircleMeshInfo
        {
            public D2D1_POINT_2F center;
            public float radius;
            public uint sliceCount;

            public CircleMeshInfo(in D2D1_POINT_2F center, float radius, uint sliceCount)
            {
                this.center = center;
                this.radius = radius;
                this.sliceCount = sliceCount;
                if (this.sliceCount < 3)
                    this.sliceCount = 3;
            }
        }

        public struct EllipseMeshInfo
        {
            public D2D1_POINT_2F center;
            public float width;
            public float height;
            public float rotation;
            public uint sliceCount;

            public EllipseMeshInfo(in D2D1_POINT_2F center, float width, float height, float rotation, uint sliceCount)
            {
                this.center = center;
                this.width = width;
                this.height = height;
                this.rotation = rotation;
                this.sliceCount = sliceCount;
                if (this.sliceCount < 3)
                    this.sliceCount = 3;
            }
        }

        public static ID2D1Mesh CreateCircleMesh(
            ID2D1RenderTarget renderTarget,
            in D2D1MeshBuilder.CircleMeshInfo meshInfo,
            out D2D1_TRIANGLE[] meshData)
        {
            if (meshInfo.sliceCount < 3)
                throw new ArgumentOutOfRangeException(nameof(meshInfo), "The slice count should be greater than 2.");

            ID2D1Mesh mesh = renderTarget.CreateMesh();

            int hr = mesh.OpenSink();
            if (hr < 0)
                throw new Exception.DxException("Failed to open mesh sink", hr);

            float theta = 2 * (float)Math.PI / meshInfo.sliceCount;
            D2D1_POINT_2F[] points = new D2D1_POINT_2F[meshInfo.sliceCount];
            for (uint i = 0; i < meshInfo.sliceCount; i++)
            {
                points[i] = new D2D1_POINT_2F(
                    meshInfo.center.x + meshInfo.radius * (float)Math.Cos(i * theta),
                    meshInfo.center.y + meshInfo.radius * (float)Math.Sin(i * theta)
                    );
            }

            D2D1_TRIANGLE[] triangles = new D2D1_TRIANGLE[meshInfo.sliceCount];

            for (uint i = 0; i < meshInfo.sliceCount; i++)
            {
                triangles[i].point1 = meshInfo.center;
                triangles[i].point2 = points[i];
                triangles[i].point3 = points[i == (meshInfo.sliceCount - 1) ? 0 : i + 1];
            }

            mesh.AddTriangles(triangles);

            meshData = triangles;

            return mesh;
        }

        public static void AddCircleMesh(
            ID2D1Mesh mesh,
            in D2D1MeshBuilder.CircleMeshInfo meshInfo,
            out D2D1_TRIANGLE[] meshData)
        {
            if (meshInfo.sliceCount < 3)
                throw new ArgumentOutOfRangeException(nameof(meshInfo), "The slice count should be greater than 2.");

            if (!mesh.SinkOpened)
            {
                int hr = mesh.OpenSink();
                if (hr < 0)
                    throw new Exception.DxException("Failed to open mesh sink", hr);
            }

            float theta = 2 * (float)Math.PI / meshInfo.sliceCount;
            D2D1_POINT_2F[] points = new D2D1_POINT_2F[meshInfo.sliceCount];
            for (uint i = 0; i < meshInfo.sliceCount; i++)
            {
                points[i] = new D2D1_POINT_2F(
                    meshInfo.center.x + meshInfo.radius * (float)Math.Cos(i * theta),
                    meshInfo.center.y + meshInfo.radius * (float)Math.Sin(i * theta)
                    );
            }

            D2D1_TRIANGLE[] triangles = new D2D1_TRIANGLE[meshInfo.sliceCount];

            for (uint i = 0; i < meshInfo.sliceCount; i++)
            {
                triangles[i].point1 = meshInfo.center;
                triangles[i].point2 = points[i];
                triangles[i].point3 = points[i == (meshInfo.sliceCount - 1) ? 0 : i + 1];
            }

            mesh.AddTriangles(triangles);

            meshData = triangles;
        }

        public static ID2D1Mesh CreateEllipseMesh(
            ID2D1RenderTarget renderTarget,
            in D2D1MeshBuilder.EllipseMeshInfo meshInfo,
            out D2D1_TRIANGLE[] meshData)
        {
            if (meshInfo.sliceCount < 3)
                throw new ArgumentOutOfRangeException(nameof(meshInfo), "The slice count should be greater than 2.");

            ID2D1Mesh mesh = renderTarget.CreateMesh();

            int hr = mesh.OpenSink();
            if (hr < 0)
                throw new Exception.DxException("Failed to open mesh sink", hr);

            float a = meshInfo.width;
            float b = meshInfo.height;
            float e = (float)Math.Sqrt(1 - (b / a) * (b / a));

            float theta = 2 * (float)Math.PI / meshInfo.sliceCount;
            float rotation = meshInfo.rotation * (float)Math.PI / 180;

            D2D1_POINT_2F[] points = new D2D1_POINT_2F[meshInfo.sliceCount];
            for (uint i = 0; i < meshInfo.sliceCount; i++)
            {
                float r = b / (float)Math.Sqrt(1 - Math.Pow(e * Math.Cos(i * theta - rotation), 2));

                points[i] = new D2D1_POINT_2F(
                    meshInfo.center.x + r * (float)Math.Cos(i * theta),
                    meshInfo.center.y + r * (float)Math.Sin(i * theta)
                    );
            }

            D2D1_TRIANGLE[] triangles = new D2D1_TRIANGLE[meshInfo.sliceCount];

            for (uint i = 0; i < meshInfo.sliceCount; i++)
            {
                triangles[i].point1 = meshInfo.center;
                triangles[i].point2 = points[i];
                triangles[i].point3 = points[i == (meshInfo.sliceCount - 1) ? 0 : i + 1];
            }

            mesh.AddTriangles(triangles);

            meshData = triangles;

            return mesh;
        }

        public static void AddEllipseMesh(
            ID2D1Mesh mesh,
            in D2D1MeshBuilder.EllipseMeshInfo meshInfo,
            out D2D1_TRIANGLE[] meshData)
        {
            if (meshInfo.sliceCount < 3)
                throw new ArgumentOutOfRangeException(nameof(meshInfo), "The slice count should be greater than 2.");

            if (!mesh.SinkOpened)
            {
                int hr = mesh.OpenSink();
                if (hr < 0)
                    throw new Exception.DxException("Failed to open mesh sink", hr);
            }

            float a = meshInfo.width;
            float b = meshInfo.height;
            float e = (float)Math.Sqrt(1 - (b / a) * (b / a));

            float theta = 2 * (float)Math.PI / meshInfo.sliceCount;
            float rotation = meshInfo.rotation * (float)Math.PI / 180;

            D2D1_POINT_2F[] points = new D2D1_POINT_2F[meshInfo.sliceCount];
            for (uint i = 0; i < meshInfo.sliceCount; i++)
            {
                float r = b / (float)Math.Sqrt(1 - Math.Pow(e * Math.Cos(i * theta - rotation), 2));

                points[i] = new D2D1_POINT_2F(
                    meshInfo.center.x + r * (float)Math.Cos(i * theta),
                    meshInfo.center.y + r * (float)Math.Sin(i * theta)
                    );
            }

            D2D1_TRIANGLE[] triangles = new D2D1_TRIANGLE[meshInfo.sliceCount];

            for (uint i = 0; i < meshInfo.sliceCount; i++)
            {
                triangles[i].point1 = meshInfo.center;
                triangles[i].point2 = points[i];
                triangles[i].point3 = points[i == (meshInfo.sliceCount - 1) ? 0 : i + 1];
            }

            mesh.AddTriangles(triangles);

            meshData = triangles;
        }

        public static void SaveMeshDataToXML(
            D2D1_TRIANGLE[] triangles,
            string saveFilePath,
            string meshName = null   
            )
        {
            XmlDocument document = new XmlDocument();

            var declaration = document.CreateXmlDeclaration("1.0", "utf-8", null);
            XmlNode root = document.CreateElement("mesh");

            XmlAttribute name = document.CreateAttribute("name");
            name.Value = meshName ?? "";
            root.Attributes.Append(name);

            for (int i = 0; i < triangles.Length; i++)
            {
                ref D2D1_TRIANGLE current = ref triangles[i];

                XmlNode triangle = document.CreateElement("triangle");

                XmlNode point1 = document.CreateElement("point");
                XmlNode point1X = document.CreateElement("x");
                point1X.InnerText = current.point1.x.ToString();
                XmlNode point1Y = document.CreateElement("y");
                point1Y.InnerText = current.point1.y.ToString();
                point1.AppendChild(point1X);
                point1.AppendChild(point1Y);

                XmlNode point2 = document.CreateElement("point");
                XmlNode point2X = document.CreateElement("x");
                point2X.InnerText = current.point2.x.ToString();
                XmlNode point2Y = document.CreateElement("y");
                point2Y.InnerText = current.point2.y.ToString();
                point2.AppendChild(point2X);
                point2.AppendChild(point2Y);

                XmlNode point3 = document.CreateElement("point");
                XmlNode point3X = document.CreateElement("x");
                point3X.InnerText = current.point3.x.ToString();
                XmlNode point3Y = document.CreateElement("y");
                point3Y.InnerText = current.point3.y.ToString();
                point3.AppendChild(point3X);
                point3.AppendChild(point3Y);

                triangle.AppendChild(point1);
                triangle.AppendChild(point2);
                triangle.AppendChild(point3);

                root.AppendChild(triangle);
            }

            document.AppendChild(declaration);
            document.AppendChild(root);

            document.Save(saveFilePath);
        }

        public static D2D1_TRIANGLE[] LoadMeshDataFromXML(string saveFilePath)
        {
            XmlDocument document = new XmlDocument();
            document.Load(saveFilePath);

            XmlNode root = document.SelectSingleNode("mesh");

            XmlNodeList triangles = root.SelectNodes("triangle");

            D2D1_TRIANGLE[] meshData = new D2D1_TRIANGLE[triangles.Count];
            for (int i = 0; i < meshData.Length; i++)
            {
                XmlNode triangle = triangles[i];

                XmlNodeList points = triangle.SelectNodes("point");
                if (points.Count != 3)
                    throw new XmlException($"The {i}th triangle does not have exactly 3 points.");

                ref D2D1_TRIANGLE currData = ref meshData[i];

                XmlNode point1 = points[0];
                XmlNode point1X = point1.SelectSingleNode("x");
                XmlNode point1Y = point1.SelectSingleNode("y");
                if (point1X == null || point1Y == null)
                    throw new XmlException($"The {i}th triangle does not have correct points.");
                currData.point1.x = Convert.ToSingle(point1X.InnerText);
                currData.point1.y = Convert.ToSingle(point1Y.InnerText);

                XmlNode point2 = points[1];
                XmlNode point2X = point2.SelectSingleNode("x");
                XmlNode point2Y = point2.SelectSingleNode("y");
                if (point2X == null || point2Y == null)
                    throw new XmlException($"The {i}th triangle does not have correct points.");
                currData.point2.x = Convert.ToSingle(point2X.InnerText);
                currData.point2.y = Convert.ToSingle(point2Y.InnerText);

                XmlNode point3 = points[2];
                XmlNode point3X = point3.SelectSingleNode("x");
                XmlNode point3Y = point3.SelectSingleNode("y");
                if (point3X == null || point3Y == null)
                    throw new XmlException($"The {i}th triangle does not have correct points.");
                currData.point3.x = Convert.ToSingle(point3X.InnerText);
                currData.point3.y = Convert.ToSingle(point3Y.InnerText);
            }

            return meshData;
        }
        public static void SaveMeshDataToJson(
            D2D1_TRIANGLE[] triangles,
            string saveFilePath,
            string meshName = null
            )
        {
            using (FileStream stream = new FileStream(saveFilePath, FileMode.Create))
            {
                using (Utf8JsonWriter json = new Utf8JsonWriter(stream, new JsonWriterOptions() { Indented = true }))
                {
                    json.WriteStartObject();

                    json.WriteString("name", meshName ?? "");

                    json.WriteStartArray("data");

                    for (int i = 0; i < triangles.Length; i++)
                    {
                        ref D2D1_TRIANGLE current = ref triangles[i];

                        json.WriteStartObject();

                        json.WriteStartObject("point1");
                        json.WriteNumber("x", current.point1.x);
                        json.WriteNumber("y", current.point1.y);
                        json.WriteEndObject();

                        json.WriteStartObject("point2");
                        json.WriteNumber("x", current.point2.x);
                        json.WriteNumber("y", current.point2.y);
                        json.WriteEndObject();

                        json.WriteStartObject("point3");
                        json.WriteNumber("x", current.point3.x);
                        json.WriteNumber("y", current.point3.y);
                        json.WriteEndObject();

                        json.WriteEndObject();
                    }

                    json.WriteEndArray();

                    json.WriteEndObject();

                    json.Flush();
                }
            }
        }

        public static D2D1_TRIANGLE[] LoadMeshDataFromJson(string saveFilePath)
        {
            using (FileStream stream = new FileStream(saveFilePath, FileMode.Open))
            {
                JsonDocument document = JsonDocument.Parse(stream);

                JsonElement root = document.RootElement;
                JsonElement data = root.GetProperty("data");

                int triangleCount = data.GetArrayLength();
                D2D1_TRIANGLE[] meshData = new D2D1_TRIANGLE[triangleCount];

                for (int i = 0; i < triangleCount; i++)
                {
                    ref D2D1_TRIANGLE triangle = ref meshData[i];

                    JsonElement triangleData = data[i];

                    JsonElement point1 = triangleData.GetProperty("point1");
                    JsonElement point1X = point1.GetProperty("x");
                    JsonElement point1Y = point1.GetProperty("y");
                    triangle.point1.x = point1X.GetSingle();
                    triangle.point1.y = point1Y.GetSingle();

                    JsonElement point2 = triangleData.GetProperty("point2");
                    JsonElement point2X = point2.GetProperty("x");
                    JsonElement point2Y = point2.GetProperty("y");
                    triangle.point2.x = point2X.GetSingle();
                    triangle.point2.y = point2Y.GetSingle();

                    JsonElement point3 = triangleData.GetProperty("point3");
                    JsonElement point3X = point3.GetProperty("x");
                    JsonElement point3Y = point3.GetProperty("y");
                    triangle.point3.x = point3X.GetSingle();
                    triangle.point3.y = point3Y.GetSingle();
                }

                return meshData;
            }
        }
    }
}
